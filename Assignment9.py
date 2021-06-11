import cv2
import datetime

face_classifier=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
eye_classifier=cv2.CascadeClassifier("haarcascade_eye.xml")
watch_cascade = cv2.CascadeClassifier('watchcascade10stage.xml')

video=cv2.VideoCapture(0)

while True:
    
    check,frame=video.read()
    frame=cv2.resize(frame, (600,600))
    gray=cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    

    faces=face_classifier.detectMultiScale(gray,1.3,5)
    eyes=eye_classifier.detectMultiScale(gray,1.3,5)
    watches = watch_cascade.detectMultiScale(gray, 1.5, 20)
    print(faces)

    for (ax,ay,aw,ah) in watches:
          cv2.circle(frame, (int(ax+ah/2),int(ay+aw/2)), 30, (0,100,255), 2)
          cv2.imshow('Face detection', frame)
        
    
    for(x,y,w,h) in faces:
        
        cv2.circle(frame,(int(x+h/2),int(y+w/2)),130,(255,0,255),4)
        cv2.imshow('Face detection', frame)
        
       
        
  
    for(ex,ey,ew,eh) in eyes:
        cv2.circle(frame, (int(ex+eh/2),int(ey+ew/2)), 25, (127,0,255), 2)
        cv2.imshow('Face detection', frame)
        picname=datetime.datetime.now().strftime("%y-%m-%d-%H-%M")
        cv2.imwrite(picname+".jpg",frame)
   
    Key=cv2.waitKey(1)
    if Key==ord('q'):
        #release the camera
        video.release()
        #destroy all windows
        cv2.destroyAllWindows()
        break

