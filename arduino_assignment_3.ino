

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);
const int ledpin = 4;  
// setting PWM properties
const int freq = 5000;
const int p = 0;
const int reso1 = 8;
// the number of the LED pin
const int light = 5;  
// setting PWM properties
const int freq = 5000;
const int f1 = 0;
const int reso2= 8;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

 

void setup(){
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  // configure LED PWM functionalitites
  ledcSetup(f1, freq, reso2);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(light, f1);
  Serial.println("oled test");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);
}
 
void loop(){
  
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.println(h);
  Serial.print(F("%  Temperature: "));
  Serial.println(t);
  Serial.print(F("°C "));
  Serial.println(f);
  Serial.print(F("°F  Heat index: "));
  Serial.println(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  if(t<18)
  {
  ledcWrite(p, 0);  
  }
  if(t<21&&t>=18)
  {
    ledcWrite(p, 10);
  }
  if(t<26&&t>=21)
  {
    ledcWrite(p, 50);
  }
  if(t>=26&&t<30)
  {
    ledcWrite(p, 100);
  }
  if(t>=30)
  {
    ledcWrite(p, 255);
  }
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1, 10);
  // Display static text
  display.println();
    display.print("TEMPERATURE IS ");
  display.print(t);
  display.println("HUMIDITY IS ");
  display.print(h);
  display.display(); 

  int a=analogRead(15);
  Serial.println(a);
  delay(500);
  if(a<400)
  {
  ledcWrite(f1, 0);  
  }
  if(a<1000&&a>400)
  {
    ledcWrite(f1, 10);
  }
  if(a<2000&&a>1000)
  {
    ledcWrite(f1, 50);
  }
  if(a>1000&&a<3500)
  {
    ledcWrite(f1, 100);
  }
  if(a>3500)
  {
    ledcWrite(f1, 255);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
    display.print("LDR VALUE IS ");
  display.print(a);
  display.display(); 
  delay(600);
}
