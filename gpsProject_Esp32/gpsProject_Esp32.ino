// Import required libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h> 

const char* ssid = "<YOUR SSID>";
const char* password = "<YOUR PASSWORD>";
String a = "";
int i = 0;

//define jspn string for sensors
String jsonLocation ="";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


void setup(){
    Serial.begin(9600);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }

  // Print ESP8266 Local IP Address
  Serial.println(WiFi.localIP());

  server.on("/location", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", jsonLocation.c_str());
  });

  // Start server
  server.begin();
}

 
void loop(){
  

    jsonLocation = readLocation();
    //Serial.println("jsonLocation: " + jsonLocation);
    delay(3500);

}


String readLocation()
{
  //i=i+1;
   Serial.println("jsonData");
   while(Serial.available())
    {
     a = Serial.readString();
     a.trim();
     return a; //"location " + String(i);
    }
}
//© 2022 GitHub, Inc.
//Terms
//Privacy
