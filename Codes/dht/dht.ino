//Adafruit_Unified_Sensor
//#include<ESP8266WiFi.h>
#include<DHT.h>
//const char* ssid="Le 2";
//const char* pass="akul0000";
int dhtpin=0; //Input pin for Temperature and Humidity (D3)
DHT dht(dhtpin, DHT11); //Create an object of DHT class with two parameter
void setup() 
{
  Serial.begin(115200);
  pinMode(dhtpin,INPUT);  //Set pin to take input
}

void loop() 
{
  Serial.println("The Temperature is : "+(String)dht.readTemperature());  //Read Temperature
  Serial.println("The Humidity is : "+(String)dht.readHumidity());  //Read Humidity
  delay(1000);
}
