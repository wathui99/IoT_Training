#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>

const char* ssid     = "UIT Public";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "";     // The password of the Wi-Fi network

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i=0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  //GPIO
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;
    //connect server
    http.begin(String("http://leeceecclubv2.000webhostapp.com/IoT_Training/control_device/get_db_control.php"));
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //send post
    int httpCode=http.POST(String("DV_ID=LED13"));
    //get response
    String payload=http.getString();
    http.end();
    //if send successful
    if(httpCode==200) {
      if (payload=="0") {
        Serial.println("Turn OFF led");
        digitalWrite(2,HIGH);
      }
      if (payload=="1"){
        Serial.println("Turn ON led");
        digitalWrite(2,LOW);
      }
    }
    else {
      Serial.println("fail");
    }
   
  }
 delay(3000);
}
