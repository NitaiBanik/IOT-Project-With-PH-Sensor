float temparature;
int tempPin = A1;

void setup()

{

Serial.begin(9600);

}

void loop()

{

temparature = analogRead(tempPin);

temparature = temparature * 0.48828125;

Serial.print("TEMPRATURE");

Serial.print(temparature);

Serial.print(" Degree Celsius");

Serial.println();

delay(1000);

}

