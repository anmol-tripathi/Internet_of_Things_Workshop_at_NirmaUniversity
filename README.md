# Internet of Things Workshop @ Nirma University 2019
Refer this repository for the IoT Workshop at Nirma University organized under MESA's annual techno cultural colloquium, PRAVEG-2019.

<p align="center">
<img src="images/praveg.png" width="150" height="200">
</p>

## Arduino IDE Installation
Arduino IDE is an integrated development environment where you can write your programs for all compatible development boards.
During the workshop we are going to use the <b>NodeMCU 1.0 (ESP-12E Module)</b>.
NodeMCU is based on the Esperessif ESP8266-12E WiFi System-On-Chip, loaded with an open-source, Lua-based firmware. it’s perfect for IoT applications, and other situations where wireless connectivity is required.

You are required to follow the given steps to get started with programming for this workshop.
1. Go to the following link to download and install the Arduino package for the correct platform.
   https://www.arduino.cc/en/main/software
   
2. Open the Arduino IDE and click on <b>File -> Preferences</b>.

3. In  <b>Aditional Boards Manager URLs</b> add this line and click on "OK":
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   
4. Go to <b>Tools -> Board -> Boards Manager</b>, type "ESP8266" and install <i>"esp8266 by ESP8266 Community"</i>.

5. Go again to <b>Tools -> Board</b> and select "<i>NodeMCU 1.0 (ESP-12E Module)</i>".

Once you complete all the steps, you are ready to start programming on the <b>NodeMCU</b>.

## Hello Arduino
Here is your first Arduino IDE code of LED blink on ESP8266 board.
```
int led = 2;  // built-in LED.
// the setup function runs only once.
void setup() {
  Serial.begin(115200); //Set data rate in bits per second (baud) for serial data transmission.
  pinMode(led, OUTPUT);  //Initialize built-in LED as an output.
  digitalWrite(led,HIGH); //Setup led as OFF.
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, LOW);                 // turn the LED on
  Serial.println("Built-in LED is ON");   //print on the serial monitor
  delay(1000);                            // wait for a second
  digitalWrite(led, HIGH);                // turn the LED off
  Serial.println("Built-in LED is OFF");  //print on the serial monitor
  delay(1000);                            // wait for a second
}
```
You can explore more such ready made codes in the well written <b>Built-in Example</b> section of your Arduino IDE present in <b>File Menu</b>.

## Installing MyMQTT app
In one of the practical you will be required to use MQTT protocol to send and receive messages. You are required to install an Android App for the same purpose.
Refer the link below.
> https://play.google.com/store/apps/details?id=at.tripwire.mqtt.client&hl=en_IN

## Tasks
- Ultrasonic and buzzer practical (reverse parking sensor)
  OBJ: Distance→ LED(1,2,3) After 3 LED, Also Buzzer frequency matching. ALSO Distance should be visible on phone/Laptop
  Skills: Arduino coding, interfacing and controlling multiple sensors at a time.

- Snap and Light automation using microphone
  OBJ: Snap once ON/OFF. Scream for 2 sec., emergency→ Buzzer + light blinking. ALSO user should get EMERGENCY on phone and also light      state. 
  Skills: Arduino coding, interfacing and controlling multiple sensors at a time.
 
- Temperature and Pressure Mailing machine
  OBJ: Using DHT, collect data and also mail the data to email


- Web page buttons for triggering events (Wifi on NodeMCU)
- Send data to ThinkSpeak
- Start visualization using node-red

## For Your Reference
1. List of sensors available for Arduino module
  - https://www.thegeekpub.com/wiki/list-of-arduino-sensors-and-modules/

2. Cayenne App for Raspberry Pi Monitoring
  - Play store:
https://play.google.com/store/apps/details?id=com.mydevices.cayenne&hl=en_IN

  - App Store:
https://apps.apple.com/us/app/cayenne-iot-project-builder/id1057997711



