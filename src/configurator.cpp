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

#include "config.h"
#include "configurator.h"

Configurator::Configurator(Configuration &configuration)
: _configuration(configuration)
{}

uint8_t Configurator::dht22_data_pin() {
    return _configuration.value<uint8_t>("dht22_data_pin", DHT22_DATA_PIN);
}

uint32_t Configurator::main_loop_delay() {
    return _configuration.value<uint32_t>("main_loop_delay", MAIN_LOOP_DELAY);
}

std::string Configurator::mqtt_hostname() {
    return _configuration.value<std::string>("mqtt_hostname", MQTT_HOSTNAME);
}

std::string Configurator::mqtt_password() {
    return _configuration.value<std::string>("mqtt_password", MQTT_PASSWORD);
}

uint16_t Configurator::mqtt_port() {
    return _configuration.value<uint16_t>("mqtt_port", MQTT_PORT);
}

std::string Configurator::mqtt_username() {
    return _configuration.value<std::string>("mqtt_username", MQTT_USERNAME);
}

uint32_t Configurator::serial_line_speed() {
    return _configuration.value<uint32_t>("serial_line_speed", SERIAL_LINE_SPEED);
}

uint16_t Configurator::ssd1306_height() {
    return _configuration.value<uint16_t>("ssd1306_height", SSD1306_HEIGHT);
}

uint16_t Configurator::ssd1306_width() {
    return _configuration.value<uint16_t>("ssd1306_width", SSD1306_WIDTH);
}

std::string Configurator::wlan_passphrase() {
    return _configuration.value<std::string>("wlan_passphrase", WIFI_PASSPHRASE);
}

std::string Configurator::wlan_ssid() {
    return _configuration.value<std::string>("wlan_ssid", WIFI_SSID);
}
