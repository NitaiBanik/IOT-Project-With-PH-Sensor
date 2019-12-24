#define echopin  10
#define trigpin 9
const int led1 = 3;   //RED
const int led2 = 4;   //Blue
const int buzzer = 8;  //Buzzer
long duration, distance;


float temparature;
int tempPin = A1;   //Temparature


const int analogInPin = A0;  //PH_Sensor
int sensorValue = 0;
unsigned long int avgValue;
float b;
int buf[10], temp;

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

  //------------Ultrasonic--------

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn (echopin, HIGH);

  distance = duration / 58.2;
  Serial.print("Distnace= ");
  Serial.println(distance);
  delay (50);


  if (distance < 4) {
    digitalWrite(led2, HIGH);     //BLUE
    digitalWrite(led1, LOW);
    digitalWrite(buzzer, LOW);
  }

  else {
    digitalWrite(led2, LOW);     //RED
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  //------------PH_Sensor---------

  for (int i = 0; i < 10; i++)
  {
    buf[i] = analogRead(analogInPin);
    delay(10);
  }
  for (int i = 0; i < 9; i++)
  {
    for (int j = i + 1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++)
    avgValue += buf[i];
  float pHVol = (float)avgValue * 5.0 / 1024 / 6;
  float phValue = -5.70 * pHVol + 21.34;
  Serial.print("sensor = ");
  Serial.println(phValue);

  delay(20);

  //--------Temp------------

  temparature = analogRead(tempPin);
  temparature = temparature * 0.48828125;
  Serial.print("TEMPRATURE");
 
  Serial.print(" Degree Celsius = ");
  Serial.println();
  delay(1000);

  
}
