#include<ESP8266WiFi.h> 
#include<PubSubClient.h>
#include<DHT.h>

const char* ssid="B1004"; //Add your ssid
const char* pass="thisissparta";  //Add wifi password
const char* mqttServer="192.168.1.224"; //MQTT broker
const int mqttPort=1883;  //Mention Port name of MQTT broker

//const char* mqttInput = "esp/input"; //Topic of input
//const char* mqttOutput = "esp/output"; //Topic of output

WiFiClient espclient; //Creating WiFi Client
PubSubClient client(espclient); //Creating MQTT client
int dhtpin=0;   //D3
DHT dht(dhtpin,DHT11);
void setup() 
{
  Serial.begin(115200); 
  pinMode(dhtpin,INPUT);
  
  WiFi.begin(ssid,pass);  //Begin Wifi
  while(WiFi.status()!=WL_CONNECTED)  
  {
    delay(500);
    Serial.print(".");  
  }
  Serial.println("WiFi is connected");
  Serial.println(WiFi.localIP());

  client.setServer(mqttServer,mqttPort);  //Set MQTT server and port
  client.setCallback(callback);
  
  while(!client.connected())  //Connect to MQTT Broker
  {
    Serial.println("Reconnecting to MQTT Server");
    if(client.connect("client_name"))
    {
      Serial.println("MQTT broker connected");
    }
    else
    {
      Serial.println("Failed with state");
      Serial.println(client.state());
      Serial.println("Trying again in 3 sec");
      delay(3000);
    }
  }
  client.subscribe("esp/input");
  client.publish("esp/output","Heyy broo!"); 
    
}
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  String temp="";
  Serial.print("Message:");
  for (int i = 0; i < length; i++) 
  {
    temp+=(char)payload[i];
  }
  Serial.println(temp);
  if(temp=="temp")
  {
    String reading=(String)dht.readTemperature();
    client.publish("esp/output/temp",(char *) reading.c_str());
    Serial.println(reading);
  }
  else if(temp=="hum")
  {
    String reading=(String)dht.readHumidity();
    Serial.println(reading);
    client.publish("esp/output/hum",(char *) reading.c_str());
  }
}
void loop() 
{
  client.loop();
}
