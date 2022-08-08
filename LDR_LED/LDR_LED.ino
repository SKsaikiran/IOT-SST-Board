int blue=2;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(blue,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int ldr=analogRead(A0);
  Serial.println(ldr);
  if(ldr>500)
  {
    digitalWrite(blue,HIGH);
    delay(1000);
  }
  digitalWrite(blue,LOW);
}
