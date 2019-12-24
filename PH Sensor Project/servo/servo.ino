#include<Servo.h>
Servo Sv;

int pin1  = 12;
void setup() {
Sv.attach(12);
Sv.write(0);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  int x = 5;
  while(1){
    
 Sv.write(i);
  i+=x;
  delay(100);
  if(i>=178 || i<=0){
    
  x *=-1;
  }
  }

}
