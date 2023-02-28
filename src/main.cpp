//
// Copyright (c) 2023 Ralph Rogge.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <sstream>
#include <string>

#include <Arduino.h>

#include "configuration.h"
#include "configurator.h"
#include "dht22_sensor.h"
#include "publish_sensor_data_action.h"
#include "serial_line.h"
#include "ssd1306_display.h"
#include "mqtt_message_queue.h"
#include "wlan_network_device.h"

static std::string chip_id();
static void connect_to_mqtt();
static void connect_to_wlan();
static std::string relative_humidity_topic();
static std::string temperature_topic();
static void reconnect_to_mqtt();
static void reconnect_to_wlan();
static void setup_dht22();
static void setup_mqtt();
static void setup_ssd1306();
static void setup_serial_line();
static void setup_wlan();

static Configuration configuration;
static Configurator configurator(configuration);
static DHT22Sensor dht22(configurator);
static MQTTMessageQueue mqtt(configurator, relative_humidity_topic(), temperature_topic());
static SerialLine serial_line(configurator);
static SSD1306Display ssd1306(configurator);
static WLANNetworkDevice wlan(configurator);

std::string chip_id() {
    std::stringstream buffer;
    buffer << std::hex << EspClass::getChipId();
    return buffer.str();
}

void connect_to_mqtt() {
    serial_line.print("HOSTNAME: "); serial_line.println(mqtt.hostname());
    serial_line.print("PORT: "); serial_line.println(mqtt.port());
    serial_line.print("USERNAME: "); serial_line.println(mqtt.username());
    while (!mqtt.is_connected()) {
        mqtt.connect();
        delay(500);
    }
}

void connect_to_wlan() {
    serial_line.print("SSID: "); serial_line.println(wlan.ssid());
    while (!wlan.is_connected()) {
        wlan.connect();
        delay(500);
    }
    serial_line.print("IP: "); serial_line.println(wlan.ip_address());
    serial_line.print("MAC: "); serial_line.println(wlan.mac_address());
    serial_line.print("ID: "); serial_line.println(chip_id());
}

void loop() {
    if (!wlan.is_connected()) {
        reconnect_to_wlan();
    }
    if (!mqtt.is_connected()) {
        reconnect_to_mqtt();
    }
    PublishSensorDataAction::execute(ssd1306, dht22, mqtt);
    delay(configurator.main_loop_delay());
}

void reconnect_to_mqtt() {
    serial_line.println("Reconnecting to MQTT.");
    connect_to_mqtt();
}

void reconnect_to_wlan() {
    serial_line.println("Reconnecting to WLANNetworkDevice.");
    connect_to_wlan();
}

std::string relative_humidity_topic() {
    std::stringstream buffer;
    buffer << "delta-t/" << chip_id() << "/dht22/relative_humidity";
    return buffer.str();
}

std::string temperature_topic() {
    std::stringstream buffer;
    buffer << "delta-t/" << chip_id() << "/dht22/temperature";
    return buffer.str();
}

void setup() {
    setup_serial_line();
    setup_dht22();
    setup_ssd1306();
    setup_mqtt();
    setup_wlan();
    connect_to_wlan();
    connect_to_mqtt();
}

void setup_dht22() {
    dht22.setup();
    serial_line.println("DHT22 ... ok.");
}

void setup_mqtt() {
    mqtt.setup();
    serial_line.println("MQTT ... ok.");
}

void setup_serial_line() {
    serial_line.setup();
    while (!serial_line.is_ready()) {
        delay(100);
    }
    serial_line.println("Serial line ... ok.");
}

void setup_ssd1306() {
    ssd1306.setup();
    serial_line.println("SSD1306 ... ok.");
}

void setup_wlan() {
    wlan.setup();
    serial_line.println("WLAN ... ok.");
}