void setup() 
{
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);//GPIO16
  pinMode(16,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  digitalWrite(16,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
  digitalWrite(16,LOW);
  delay(1000);
}  
