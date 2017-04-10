# TODO

 * Stopped at "part 2"

---

# Talking to Things With MQTT

---

# Live Demo

---

# What is it?

  * Designed in 1999 at IBM. Opensourced in 2010.
  * Goals: Light weight, minimal battery loss, bandwidth.
  * Not actually a message queue.
  * MQTT is not an acronym

---

# Advantages
 * Websockets
 * Low bandwidth
 * Standardization
 * Well written standard docs (really!)
 * Transmit anything! (JSON, XML, binary, whatever!)

---

# Alternatives

 * REST (not good)
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

 * Organize via "topics"
 * Example: `house/airconditioner/temp_sensors/1`
 * Sensors "publish" to topics.
 * Consumers "subscribe" to get latest readings.
 * Chat demo among participants?

---

# Advanced Stuff

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

---
