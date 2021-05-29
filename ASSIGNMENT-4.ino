
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int trigpin=4;
int echopin=5;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  delay(3000);
  SerialBT.begin("ESP32test"); //Bluetooth device name
 
}

void loop(){
  digitalWrite(trigpin,LOW);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  int duration=pulseIn(echopin,HIGH);
  int distance=(duration*0.034)/2;
  SerialBT.write(distance);
  delay(1000);
  Serial.println(distance);
  if (SerialBT.available()) {
    char a = SerialBT.read();
    if(a == '0'){
      digitalWrite(2,LOW);
     } 
    else if(a == '1'){
      digitalWrite(2,HIGH);
    }
    delay(500);
   }
}
