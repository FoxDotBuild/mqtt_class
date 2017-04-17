
# Things Talking to Things With MQTT

### Rick Carlino

**TODO:** Acquire "bell" source code or write fresh example.
**TODO:** Setup projector at space.

---

# About This Talk

 * Topic
 * Target Audience
 * About You
 * About Me
 * Other Stuff

---

# What We Want

 * Sending information remotely
 * Sending commands remotely
 * Getting *realtime* (push) notifications from devices
 * Security and Authentication
 * Dealing with offline situations

---

# Live Demo: The Bell

**What just happened?**

---

# What Can MQTT Do?

 * "Publish" sensor data
 * "Subscribe" to user input
 * Handle disconnects
 * Handle security

---

# What Are People Making with MQTT?

---

# Robotics

![farmbot](/images/farmbot.jpg)

---

# Telemetry / Sensor Systems

![telemetry](/images/telemetry.jpg)

---

# Small Scale Hobby Projects

![hobby projects](/images/diy.jpg)

---

# What is it?

  * Designed in 1999 at IBM. Opensourced in 2010.
  * Goals: Light weight, minimal battery loss, bandwidth.
  * MQTT is not an acronym.
  * It's a message **broker**, Not actually a message queue

---

# Advantages
 * Works on Arudino, browser, desktop, mobile.
 * Optimized to save bandwidth (cellular devices)
 * Standardized
 * Standard is very compact and easy to understand
 * Well written documentation (really!)
 * Transmit anything! (JSON, XML, binary, images- whatever!)

---

# Alternatives

 * REST (not realtime)
 * Raw TCP socket (too much coding)
 * Proprietary "platforms"

---

# Clients

 * [Android MQTT clients](https://play.google.com/store/apps/details?id=at.tripwire.mqtt.client&hl=en)
 * TODO: Find iOS clients
 * [Web Browser](http://www.hivemq.com/demos/websocket-client/)

---

 # Brokers

 * Mosquitto (`sudo apt-get install mosquitto`)
 * Mosca
 * RabbitMQ (advanced)
 * AWS IoT

---

# Topics, Pub/Sub

 * Organize messages into "topics"
 * Kind of like a chatroom
 * Example: `house/airconditioner/temp_sensors/1`
 * Sensors "publish" to topics.
 * Consumers "subscribe" to get latest readings.
 * Wildcards
 * SYS topics

---

EXERCISE: MQTT Chat

[http://www.hivemq.com/demos/websocket-client/](http://www.hivemq.com/demos/websocket-client/)

---

EXERCISE: MQTT for ESP

---
# Advanced Stuff

 * "persistent" messages (message broker style messages)
 * Last will and testament
 * QoS
 * Distinction from "real" message queues.

---

# Security
 * SSL
 * Shodan and other crawlers.
 * Lax security culture.
 * Malware

---

# Available Hardware

 * ESP
 * Ardunio shields?

---

# Extras

 * MQTT-SN
 * AWS IoT
 * https://shiftr.io/

---
