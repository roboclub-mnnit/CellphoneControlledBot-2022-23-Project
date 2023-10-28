//Esp01 Module Code

#include <ESP8266WiFi.h>

String  str;
WiFiServer server(80);

void setup()
{
  str = "";

  Serial.begin(9600);
  WiFi.disconnect();
  delay(2000);
  WiFi.begin("Wifi", "12345678");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    Serial.print("...");
    delay(300);
  }
  Serial.println(WiFi.localIP());
  server.begin();

}


void loop()
{

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  str = (client.readStringUntil('\r'));
//  Serial.println(str);
  client.write("data recived");

  str.remove(0, 5);
  str.remove(str.length() - 9, 9);

  Serial.println(str);

}
