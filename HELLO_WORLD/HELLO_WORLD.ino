int a=10;
float b=20.99;
void setup() 
{
  // put your setup code here, to run once:
 Serial.begin(9600);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  Serial.println(a);
  Serial.println(b);
}
