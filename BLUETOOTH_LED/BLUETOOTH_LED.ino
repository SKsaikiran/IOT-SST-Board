/************ BLUETOOTH_LED *******************/
 #include <SoftwareSerial.h>
 SoftwareSerial mySerial(14,12); // RX(D5),TX(D6)
 void setup() 
 {
  // Open serial communications and wait for port to open:
     Serial.begin(9600);
     mySerial.begin(9600);
    pinMode(2,OUTPUT);
  }
 void loop() 
 { 
  char  val;
   if (mySerial.available()) 
    {
        val=mySerial.read();
        if(val=='1')
        digitalWrite(2,HIGH);
        if(val=='0')
        digitalWrite(2,LOW);
        }
 }
