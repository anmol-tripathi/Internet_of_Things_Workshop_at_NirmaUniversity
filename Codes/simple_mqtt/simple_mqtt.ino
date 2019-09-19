#include<ESP8266WiFi.h> 
#include<PubSubClient.h>
const char* ssid="B1004"; //Add your ssid
const char* pass="thisissparta";  //Add wifi password
const char* mqttServer="192.168.1.224"; //MQTT broker
const int mqttPort=8000;  //Mention Port name of MQTT broker
const char* mqttTopic = "esp/test"; //Topic of interest
WiFiClient espclient; //Creating WiFi Client
PubSubClient client(espclient); //Creating MQTT client
int led=5;

void setup() 
{
  Serial.begin(115200); 
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
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
  if(temp=="on")
  {
    digitalWrite(led,HIGH);
  }
  else if(temp=="off")
    digitalWrite(led,LOW);
}
void loop() 
{
  client.loop();
}
