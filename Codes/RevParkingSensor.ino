/*
  TASK 1:
  Reverse Parking Sensor
*/

// Pin initialization
const int trigPin = D0;
const int echoPin = D1;
const int ledPin = D2;
const int ledPin2 = D3;
const int ledPin3 = D4;
const int buzzerPin = D5;

long duration;
int distance;
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); // Trigger Pin of Ultrasonic
  pinMode(echoPin, INPUT); // Echo Pin of Ultrasonic
  pinMode(ledPin, OUTPUT); // First LED
  pinMode(ledPin2, OUTPUT); // Second LED
  pinMode(ledPin3, OUTPUT); // Third LED
  pinMode(buzzerPin, OUTPUT); // Buzzer
}

void loop() {
int count =0;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // Triggering ON
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

if(distance < 30 && distance > 20)
{
  digitalWrite(ledPin,HIGH);
  while(count!=5)
  {
    digitalWrite(buzzerPin,HIGH);
    delay(300);
    digitalWrite(buzzerPin,LOW);
    delay(300);
    count=count+1;
  }
}

else if(distance < 20 && distance > 10)
{
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin2,HIGH);
  while(count!=5)
  {
    digitalWrite(buzzerPin,HIGH);
    delay(200);
    digitalWrite(buzzerPin,LOW);
    delay(200);
    count=count+1;
  }
}


else if(distance < 10)
{
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  while(count!=5)
  {
    digitalWrite(buzzerPin,HIGH);
    delay(50);
    digitalWrite(buzzerPin,LOW);
    delay(50);
    count=count+1;
  }
}

else if(distance < 3)
{
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  while(count!=30)
  {
    digitalWrite(buzzerPin,HIGH);
    delay(5);
    digitalWrite(buzzerPin,LOW);
    delay(5);
    count=count+1;
  }
}
}
