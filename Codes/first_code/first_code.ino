
int led = 2;  // built-in LED.
// the setup function runs only once.
void setup() {
  Serial.begin(115200); //Set data rate in bits per second (baud) for serial data transmission.
  pinMode(led, OUTPUT);  //Initialize built-in LED as an output.
  digitalWrite(led,HIGH); //Setup led as OFF.
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, LOW);   // turn the LED on
  Serial.println("Built-in LED is ON"); //print on the serial monitor
  delay(1000);                       // wait for a second
  digitalWrite(led, HIGH);    // turn the LED off
  Serial.println("Built-in LED is OFF"); //print on the serial monitor
  delay(1000);                       // wait for a second
}
