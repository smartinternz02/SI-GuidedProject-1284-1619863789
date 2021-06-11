from ibmcloudant.cloudant_v1 import CloudantV1
from ibmcloudant import CouchDbSessionAuthenticator
from ibm_cloud_sdk_core.authenticators import BasicAuthenticator

authenticator = BasicAuthenticator(
    'apikey-v2-26g9t1z3q0xklw9t9abzzlugdatwuhb184e6alna2xmt',
    '569e622c6ed6c4118b9877c19391f54e')

service = CloudantV1(authenticator=authenticator)

service.set_service_url('https://apikey-v2-26g9t1z3q0xklw9t9abzzlugdatwuhb184e6alna2xmt:569e622c6ed6c4118b9877c19391f54e@b121a610-4bb6-47e9-9aed-3191c167e220-bluemix.cloudantnosqldb.appdomain.cloud')
#response = service.put_database(db='products', ).get_result()
#print(response)


products_doc = {
    "_id" : "Rachana",
    "name" : "GCET",
    "Domain" : "IoT"
    }

response = service.post_document(db='assgn7', document=products_doc).get_result()

print(response)


