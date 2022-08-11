#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <addons/TokenHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID " "//WIFI ID
#define WIFI_PASSWORD " "//WIFI PASSWORD

//For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyBGzWjAUjVNDBKwcvR1ZVm7LEpgzWjX6NQ"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://fir-demo-56b8f-default-rtdb.firebaseio.com/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "srinvasanm1207@gmail.com"
#define USER_PASSWORD "password"


//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long lastReadTime = 0;
String prevData = "";
void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);
}

void loop()
{
  if (Firebase.ready() && Serial.available())
  {
    //Your text messages
    String user1Data = Serial.readString();
    //Serial.printf("User 2 :  %s\n", Firebase.setString(fbdo, "/user2/data",user1Data) ? user1Data : fbdo.errorReason().c_str());
    Firebase.setString(fbdo, "/user2/data",user1Data);
    Serial.print("User 2 :");
    Serial.println(user1Data);
  }

  if(millis() - lastReadTime > 2000)
  {
    //Reading text messages
      Firebase.getString(fbdo, "/user1/data");
      String user2Data = fbdo.to<String>();
      if(prevData != user2Data)
      {
        Serial.println("User 1 : "+user2Data);  
      }
      prevData = user2Data;
      lastReadTime = millis();
  } 
}
