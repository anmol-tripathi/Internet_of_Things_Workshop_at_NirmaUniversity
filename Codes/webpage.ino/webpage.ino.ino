/* IoT Workshop@Nirma University
 *  Practical - WiFiServer
 *  Author - Akul Agrawal
 */

#include <ESP8266WiFi.h>

const char* ssid = "Le 2";
const char* pass = "akul0000";
int led=2;
String header;
WiFiServer server(80);  //Create an instance of ESP server at specified port number

void setup() {
  Serial.begin(115200); //For Serial Monitor
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  WiFi.begin(ssid,pass); //This connects esp to a network
  while (WiFi.status() != WL_CONNECTED) //Check WiFi status
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnected! IP is - ");
  Serial.println(WiFi.localIP()); //Returns IP address of the Wifi Shield.
  server.begin(); // Tells server to begin listening to incoming connections
}

void loop() {
  WiFiClient client =server.available(); //If no client, then false //Create a WifiClient
  if(client)
  {
    Serial.println("New Client arrived");
    String currentLine="";
    while(client.connected())
    {
      if(client.available())
      {
        char c=client.read();
        header+=c;
        if(c=='\n')
        {
//          Serial.println("Heyy This is THANOS");
          if(currentLine.length()==0)
          {
            Serial.println("This is currentLine"+currentLine);
            client.println("<html><body><center><h1>Akul</h1></body></html>");
            client.println("<p><a href=\"/on\"><button>ON</button></a></p>");
            client.println("<p><a href=\"/off\"><button>OFF</button></a></p>");
            client.println("</center></body></html>");
            if(header.indexOf("GET /on")>=0)
            {
              Serial.println("Congrats is ONN!!");
              digitalWrite(led,LOW);
              
            }
            else if (header.indexOf("GET /off")>=0)
            {
              Serial.println("Ohh no, it is OFF!!");
              digitalWrite(led,HIGH);
            }
            break;
          }
          else
            currentLine="";
        }
        else if (c != '\r')
        {
          currentLine+=c;
        }
      }
      
    }
    header="";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
