/*************************************************************
SMART DRIP IRRIGATION
 *************************************************************/
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud.
#define BLYNK_TEMPLATE_ID "  "//Template ID
#define BLYNK_DEVICE_NAME " "//Device name
#define BLYNK_AUTH_TOKEN " "//Auth token
#define BLYNK_PRINT Serial
#define Motor D2 //Motor pin assigned to GPIO D2
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = " ";//WIFI ID(case sensitive)
char pass[] = " ";//WIFI PASSWORD(case sensitive)
BlynkTimer timer;
// This function is called every time the device is connected to the Blynk.Cloud.
void moisture() 
{
  int value = analogRead(A0);//reading soil moisture sensor value.
  value = map(value, 0, 1023, 0, 100);
  Serial.println(value);
}
  void setup() 
  {
  pinMode(Motor,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  }
void loop()
{
   float moisture_percentage;
  moisture_percentage =  ( 100.00 - ( (analogRead(A0)/1024.00)*100));
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  if(moisture_percentage<=30)
  {
    Serial.println("ON");
    digitalWrite(Motor,HIGH);
  }
 else
 {
  Serial.println("OFF");
  digitalWrite(Motor,LOW);
 }
  Blynk.virtualWrite(V0,moisture_percentage);
  delay(1000);  
  Blynk.run();
  timer.run();  
} 
