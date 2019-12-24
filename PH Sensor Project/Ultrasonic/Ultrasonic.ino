#define echopin  10
#define trigpin 9
const int led1 = 3;   //RED
const int led2 = 4;   //Green
const int buzzer = 8;  //Buzzer

long duration, distance;

void setup() {

  Serial.begin(9600);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode (buzzer, OUTPUT);

}

void loop ()
{

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn (echopin, HIGH);

  distance = duration / 58.2;
  Serial.println(distance);
  delay (50);


  if (distance < 20) {
    digitalWrite(led1, HIGH);     //Red
    digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
  }

  else {
    digitalWrite(led1, LOW);     //Green
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer,HIGH);
  }

}
