/*************************************************************
SMART IRRIGATION
 *************************************************************/
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
#define BLYNK_TEMPLATE_ID "  "//Template ID
#define BLYNK_DEVICE_NAME " "//Device name
#define BLYNK_AUTH_TOKEN " "//Auth token
#define BLYNK_PRINT Serial
#define BLYNK_PRINT Serial
#define Motor D2
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = " ";//WIFI ID(case sensitive)
char pass[] = " ";//WIFI PASSWORD(case sensitive)
BlynkTimer timer;
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
void moisture() {
  int value = analogRead(A0);
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
