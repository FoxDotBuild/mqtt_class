#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char *ssid = "Fox.Build";
const char *password = "Fox.Build";
const char *mqtt_server = "clowncar.fox.build";
const char *username = "shane";
const char *mqttpass = "shane";

//unsigned long duration, distance; // Duration used to calculate distance

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi()
{

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//This callback routine for ringing the bell. It is not used for the button.
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Ring the bell if 1 was received as first character
  if ((char)payload[0] == '1')
  {

    digitalWrite(5, HIGH); // Ring the bell
    delay(50);             // This is the on time for the bell. Above 100 is unbearable.
    digitalWrite(5, LOW);  // Turn the bell off
  }
  else
  {
    digitalWrite(5, LOW); // Not needed in this sketch. Does nothing
  }
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    delay(2000); // May consider reducing thisfor more immediate responses?
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX); // I do not think this is necessary. Is the client ID important?
    // Attempt to connect
    if (client.connect(clientId.c_str(), username, mqttpass))
    { // This is the major change to make this sketch work. Added username, mqttpass
      Serial.println("connected");
      // ... and resubscribe
      client.subscribe("/fox/build/in");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000); // Changed this to 1000 and the bell rings more promptly.
    }
  }
}

void setup()
{
  //  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(2, INPUT_PULLUP); // This is the GPIO for the button. Not sure if the INPUT_PULLUP is necessary or effective.
                            // There is an input pullup but I am not sure if it can be defined by hardware like on an UNO.
                            // This is GPIO 2 which is D4 on the Wemos. https://www.wemos.cc/sites/default/files/2016-09/mini_new_V2.pdf
}

void loop()
{

  if (!client.connected())
  {
    reconnect();
  }

  client.loop();

  long now = millis();
  if (now - lastMsg > 100)
  { // Checks reading every 100 ms. Probably sufficient.
    lastMsg = now;
    ++value;
    int sensorVal = digitalRead(2);
    client.subscribe("/fox/build/in");

    if (!sensorVal)
    {
      snprintf(msg, 75, "%d", !sensorVal);
      Serial.print("Publish message: ");
      Serial.println(msg);
      client.publish("/fox/build/in", msg);
    }
  }
}
