void setup() 
{
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  digitalWrite(4, LOW);
 Int count =0;
}
void loop() 
{ 
 If(count<=5) 
 {
  digitalWrite(0, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  delay(1000);
  digitalWrite(0, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(0, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, LOW);
  delay(1000);
  digitalWrite(0, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(0, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  delay(1000);
  digitalWrite(0, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(16, LOW);
  delay(1000);
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  delay(1000);
 }
}
