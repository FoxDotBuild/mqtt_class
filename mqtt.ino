#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *SSID = "Fox.Build";
const char *WIFI_PASS = "Fox.Build";
char *TOPIC = "esp8266/mqtt_fun";
char *MQTT_SERVER = "clowncar.fox.build";
PubSubClient mqtt;

void setup()
{
  startSerial();
  showIPAddr();
}

void loop()
{
  startWifi();
  startMQTT();
  checkMessage();
}

void showIPAddr()
{
  // Print the IP address
  Serial.print("Here is my IP: ");
  Serial.print(WiFi.localIP());
}

void checkMessage()
{
}

void startSerial()
{
  Serial.begin(115200);
  delay(10);
}

void startWifi()
{
  // Connect to WiFi network
  Serial.print("\nConnecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void startMQTT()
{
  mqtt(MQTT_SERVER, 1883, handleMQTT, WiFi);
}

void handleMQTT(char *topic, byte *payload, unsigned int length)
{
  Serial.println("INCOMING MQTT!!");
}
