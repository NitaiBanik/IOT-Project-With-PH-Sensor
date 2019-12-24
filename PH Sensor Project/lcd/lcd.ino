#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int c=0;
int r=0;

void setup(){
  lcd.begin(8, 2);
  Serial.begin(9600);
  lcd.clear();
  lcd.cursor();
}

void loop()
{
  int i=0;
  if (Serial.available()) {
    while (Serial.available() > 0) {
      i=Serial.read();
      if (i==-1)
        break; 
      lcd.write(i);
      c++;
      if (c==8) {
       r=(r==1 ? 0 : 1);
       c=0;
       lcd.setCursor(c,r);
      }
      Serial.print(c);
      Serial.print("\t");
      Serial.print(r);
      Serial.println("");
    }
  }
}
