//
// Copyright (c) 2023  Ralph Rogge.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <Arduino.h>
#include <string>
#include <utility>

#include "mqtt_message_queue.h"

MQTTMessageQueue::MQTTMessageQueue(MQTTMessageQueueConfigurator &configurator, std::string relative_humidity_topic, std::string temperature_topic)
    : _client(), _hostname(configurator.mqtt_hostname()), _password(configurator.mqtt_password()), _port(configurator.mqtt_port()), _relative_humidity_topic(std::move(relative_humidity_topic)), _temperature_topic(std::move(temperature_topic)), _username(configurator.mqtt_username())
{}

MQTTMessageQueue::MQTTMessageQueue(std::string hostname, uint16_t port, std::string username, std::string password, std::string relative_humidity_topic, std::string temperature_topic)
    : _client(), _hostname(std::move(hostname)), _password(std::move(password)), _port(port), _relative_humidity_topic(std::move(relative_humidity_topic)), _temperature_topic(std::move(temperature_topic)), _username(std::move(username))
{}

void MQTTMessageQueue::connect() {
    _client.connect();
}

bool MQTTMessageQueue::is_connected() const {
    return _client.connected();
}

void MQTTMessageQueue::publish_relative_humidity(float relative_humidity) {
    std::string message = std::to_string(relative_humidity);
    _client.publish(_relative_humidity_topic.c_str(), 1, true, message.c_str());
}

void MQTTMessageQueue::publish_temperature(float temperature) {
    std::string message = std::to_string(temperature);
    _client.publish(_temperature_topic.c_str(), 1, true, message.c_str());
}

void MQTTMessageQueue::setup() {
    _client.setServer(_hostname.c_str(), _port);
    _client.setCredentials(_username.c_str(), _password.c_str());
}
