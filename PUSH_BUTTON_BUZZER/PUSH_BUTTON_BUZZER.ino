const int toggle=16; //GPIO16
int buttonstate = 0;
const int buzzer=12;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  Serial.begin(115200);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  buttonstate=digitalRead(toggle);
  Serial.print(buttonstate);
  if(buttonstate == 1)
   {
    digitalWrite(buzzer,HIGH);
   }
   else if(buttonstate == 0)
   {
   digitalWrite(buzzer,LOW);
   }   
}
