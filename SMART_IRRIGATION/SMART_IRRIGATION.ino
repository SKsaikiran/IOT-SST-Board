/*************************************************************
SMART IRRIGATION
 *************************************************************/
 // Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
 // See the Device Info tab, or Template settings
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define BLYNK_TEMPLATE_ID " "
#define BLYNK_DEVICE_NAME " "
#define BLYNK_AUTH_TOKEN " "
#define BLYNK_PRINT Serial
#define BLYNK_PRINT Serial
#define Motor D3
#define DHTPIN D4
#define Smoke D7
#define DHTTYPE    DHT11
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = " ";//WIFI ID(case sensitive)
char pass[] = " ";//WIFI PASSWORD(case sensitive)
const int Led = D3;//Assigning D3 pin for LED 
BlynkTimer timer;
// This function is called every time the device is connected to the Blynk.Cloud
DHT_Unified dht(DHTPIN, DHTTYPE);
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
void myTimerEvent()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print("Temperature: ");
  float temp = float(event.temperature);
  Serial.print(event.temperature);
  Blynk.virtualWrite(V1, temp);
  Serial.println("°C");
    
  dht.humidity().getEvent(&event);
  Serial.print("Humidity: ");
  float hum = float(event.relative_humidity);
  Serial.print(hum);
  Blynk.virtualWrite(V2, hum);
  Serial.println("%");
  Serial.println("\n-------------------------------");
 
}
void moisture() 
{
  int value = analogRead(A0);//reading soil moistor sensor value
  value = map(value, 0, 1023, 0, 100);
  Serial.println(value);
}
  void setup() 
  {
  pinMode(Motor,OUTPUT);//Assigning Motor pin D3 as output.
  pinMode(D6,OUTPUT);//Assigning D6 pin for Smoke Sensor Ground pin as output.
  pinMode(D7,OUTPUT);//Assigning D7 pin for Smoke sensor digitalpin as output.
  digitalWrite(D6,LOW);//D6 as Ground
  digitalWrite(D7,HIGH);//D7 as high
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  }
void loop()
{
   float moisture_percentage;
   int Smoke= analogRead(D7);//reading somke sensor value
  moisture_percentage =  ( 100.00 - ( (analogRead(A0)/1024.00)*100));
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  if(moisture_percentage <= 30)
  {
    Serial.println("MOTOR ON");
    digitalWrite(Motor,HIGH);
  }
 else
 {
  Serial.println("MOTOR OFF");
  digitalWrite(Motor,LOW);
 }
Serial.print("smoke value = ");
  Serial.print(Smoke);
  Serial.print(".");
  Serial.println(" ");
  if(Smoke > 190)
  {
    digitalWrite(Led,LOW);
    Serial.println("Led is OFF");
    delay(1000);
  }
  else
  {
  digitalWrite(Led,HIGH);
  Serial.println("Led is ON");
  }
  delay(500);
  Blynk.virtualWrite(V0,moisture_percentage);
  delay(1000);  
  Blynk.run();
  timer.run();  
} 
