# Delta T Sensor Node


This experimental project is about applying [clean architecture](https://github.com/r42sys/clean-architecture) to an IoT code base. Not because it's easy but because it's hard ;).

The hardware setup is quite simple: An ESP8266, a DHT22 sensor and an Adafruit SSD1306 OLED display.

Every few seconds the firmware on the ESP8266 reads temperature and relative humidity from the attached DHT22 sensor,
shows the data on the display and publishes the data via MQTT on a temperature and a relative humidity topic.

## Code

**lib/facades**

Convenience code to execute the "Publish Sensor Data" use-case.

**lib/drivers**

Code to access hardware and network, e.g. DHT22 sensor, Serial line, SSD1306 display, MQTT message queue, and WLAN 
network interface.

**lib/interface_adapters**

Code for "Publish Sensor Data" presenter, view-model, and controller plus gateway APIs.

**lib/application_business_rules**

Code for "Publish Sensor Data" interactor.
