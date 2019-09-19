/*
 * TASK 2:
 * Clap Lights
 */

void setup() {
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
}
int flag =0;

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0); 
  float voltage = sensorValue * (5.0 / 1023.0);
  if(voltage>=0.9)
  {
    if(flag == 0)
    {
      digitalWrite(D0,HIGH);
      delay(1000);
      flag =1;
    }
    else if(flag ==1) 
    {
      digitalWrite(D0,LOW);
      delay(1000);
      flag =0;
    }
  }
  Serial.println(voltage);
}
