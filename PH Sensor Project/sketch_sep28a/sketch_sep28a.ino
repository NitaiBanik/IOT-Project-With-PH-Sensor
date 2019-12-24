int l1 = 13;
int l2 = 12;
int l3 = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(l1,HIGH);
  delay(100);
  digitalWrite(l2,HIGH);
  delay(100);
   digitalWrite(l3,HIGH);
  delay(100);

   digitalWrite(l1,LOW);
  delay(100);
  digitalWrite(l2,LOW);
  delay(100);
   digitalWrite(l3,LOW);
  delay(100);

}
