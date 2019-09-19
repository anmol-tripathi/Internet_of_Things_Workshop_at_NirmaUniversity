#include<ESP8266WiFi.h>
#include <DHT.h>
#define DHTTYPE DHT11
DHT dht(5,DHTTYPE);
//String apiWritekey ="XY397TN7SYSD1JTF";
String apiWritekey ="ZQJPBXLFSGW0BDPS";
const char* ssid="B1004";
const char* password="thisissparta";
const char* server="api.thingspeak.com";
float resolution =3.3/1023;
WiFiClient client;

void setup(){
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  Serial.begin(115200);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid,password);
  Serial.print("Connecting to");
  Serial.println(ssid);
   WiFi.begin(ssid, password);
  if(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print("."); 
  }
  Serial.print("Connecting to");
  Serial.println(ssid);
}
void loop()
{
  float temp=dht.readTemperature();
  float hum=dht.readHumidity();
  if (client.connect(server,80))
  {  
    String tsData = apiWritekey;
           tsData +="&field1=";
           tsData += String(temp);
           tsData += "\r\n\r\n";
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
     //client.print(hsData);
      digitalWrite(D5,HIGH);
     Serial.print("Temperature: ");
     Serial.print(temp);
     //Serial.print("HUMIDITY: ");
     //Serial.print(hum);
     Serial.println("uploaded to Thingspeak server....");
     Serial.println();
     delay(1000);
     digitalWrite(D5,LOW);
  }
  //delay(7000);
  client.stop();
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates
  delay(15000);
  if (client.connect(server,80))
  {  
    String tsData = apiWritekey;
           tsData +="&field2=";
           tsData += String(hum);
           tsData += "\r\n\r\n";
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
     //client.print(hsData);
      digitalWrite(D6,HIGH);
     //Serial.print("Temperature: ");
     //Serial.print(temp);
     Serial.print("HUMIDITY: ");
     Serial.print(hum);
     Serial.println("uploaded to Thingspeak server....");
     Serial.println();
     delay(1000);
     digitalWrite(D6,LOW);
  }
  client.stop();
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates
  delay(15000);
}
