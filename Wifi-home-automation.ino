#include <ESP8266WiFi.h>
 
const char* ssid = "1";
const char* password = "000000002";
int ledPin = 13; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value16 = LOW;
  if (request.indexOf("/16=ON")!=-1)  {
    digitalWrite(16, HIGH);
    value16 = HIGH;
  }
  if (request.indexOf("/16=OFF")!=-1)  {
    digitalWrite(16, LOW);
    value16 = LOW;
  }
  int value5 = LOW;
  if (request.indexOf("/5=ON")!=-1)  {
    digitalWrite(5, HIGH);
    value5 = HIGH;
  }
  if (request.indexOf("/5=OFF")!=-1)  {
    digitalWrite(5, LOW);
    value5 = LOW;
  }

  int value4 = LOW;
  if (request.indexOf("/4=ON")!=-1)  {
    digitalWrite(4, HIGH);
    value4 = HIGH;
  }
  if (request.indexOf("/4=OFF")!=-1)  {
    digitalWrite(4, LOW);
    value4 = LOW;
  }
  int value0 = LOW;
  if (request.indexOf("/0=ON")!=-1)  {
    digitalWrite(0, HIGH);
    value0 = HIGH;
  }
  if (request.indexOf("/0=OFF")!=-1)  {
    digitalWrite(0, LOW);
    value0 = LOW;
  }

  int value2 = LOW;
  if (request.indexOf("/2=ON")!=-1)  {
    digitalWrite(2, HIGH);
    value2 = HIGH;
  }
  if (request.indexOf("/2=OFF")!=-1)  {
    digitalWrite(2, LOW);
    value2 = LOW;
  }

  int value14 = LOW;
  if (request.indexOf("/14=ON")!=-1)  {
    digitalWrite(14, HIGH);
    value14 = HIGH;
  }
  if (request.indexOf("/14=OFF")!=-1)  {
    digitalWrite(14, LOW);
    value14 = LOW;
  }

  int value12 = LOW;
  if (request.indexOf("/12=ON")!=-1)  {
    digitalWrite(12, HIGH);
    value12 = HIGH;
  }
  if (request.indexOf("/12=OFF")!=-1)  {
    digitalWrite(12, LOW);
    value12 = LOW;
  }

  int value13 = LOW;
  if (request.indexOf("/13=ON")!=-1)  {
    digitalWrite(13, HIGH);
    value13 = HIGH;
  }
  if (request.indexOf("/13=OFF")!=-1)  {
    digitalWrite(13, LOW);
    value13 = LOW;
  }
  
  int value15 = LOW;
  if (request.indexOf("/15=ON")!=-1)  {
    digitalWrite(15, HIGH);
    value15 = HIGH;
  }
  if (request.indexOf("/15=OFF")!=-1)  {
    digitalWrite(15, LOW);
    value15 = LOW;
  }

  int value3 = LOW;
  if (request.indexOf("/3=ON")!=-1)  {
    digitalWrite(3, HIGH);
    value3 = HIGH;
  }
  if (request.indexOf("/3=OFF")!=-1)  {
    digitalWrite(3, LOW);
    value3 = LOW;
  }

  int value1 = LOW;
  if (request.indexOf("/1=ON")!=-1)  {
    digitalWrite(1, HIGH);
    value5 = HIGH;
  }
  if (request.indexOf("/1=OFF")!=-1)  {
    digitalWrite(1, LOW);
    value1 = LOW;
  }
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("pin 16 is now: ");
 
  if(value16 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/16=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/16=OFF\"\"><button>Turn Off </button></a><br />");  

  client.print("pin 5 is now: ");
 
  if(value5 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/5=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/5=OFF\"\"><button>Turn Off </button></a><br />");
  client.print("pin 4 is now: ");
 
  if(value4 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/4=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/4=OFF\"\"><button>Turn Off </button></a><br />");

  client.print("pin 0 is now: ");
  if(value0 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/0=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/0=OFF\"\"><button>Turn Off </button></a><br />");

  client.print("pin 2 is now: ");
  if(value2 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/2=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/2=OFF\"\"><button>Turn Off </button></a><br />");  

  client.print("pin 14 is now: ");
 
  if(value14 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/14=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/14=OFF\"\"><button>Turn Off </button></a><br />");

client.print("pin 12 is now: ");
 
  if(value12 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/12=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/12=OFF\"\"><button>Turn Off </button></a><br />");  

  client.print("pin 13 is now: ");
 
  if(value13 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/13=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/13=OFF\"\"><button>Turn Off </button></a><br />");  

 client.print("pin 15 is now: ");
 
  if(value16 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/15=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/15=OFF\"\"><button>Turn Off </button></a><br />");  


  client.print("pin 3 is now: ");
 
  if(value3 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/3=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/3=OFF\"\"><button>Turn Off </button></a><br />"); 

   client.print("pin 1 is now: ");
 
  if(value1 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/1=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/1=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
