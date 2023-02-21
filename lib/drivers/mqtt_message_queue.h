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

#ifndef DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_H
#define DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_H

#include <string>

#include <AsyncMqttClient.h>

#include "message_queue_gateway.h"
#include "mqtt_message_queue_configurator.h"

/**
 * @brief This class implements the message queue gateway interface for a MQTT message queue.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on gateways.
 */
class MQTTMessageQueue : public MessageQueueGateway {
public:

    /**
     * @param configurator The MQTT message queue configurator.
     * @param relative_humidity_topic The name of the relative humidity topic.
     * @param temperature_topic The name of the temperature topic.
     */
    MQTTMessageQueue(MQTTMessageQueueConfigurator &configurator, std::string relative_humidity_topic, std::string temperature_topic);

    /**
     * @param hostname The MQTT server hostname.
     * @param port The MQTT server port.
     * @param username The MQTT username.
     * @param password The MQTT password for the username.
     * @param relative_humidity_topic The name of the relative humidity topic.
     * @param temperature_topic The name of the temperature topic.
     */
    MQTTMessageQueue(std::string hostname, uint16_t port, std::string username, std::string password, std::string relative_humidity_topic, std::string temperature_topic);

    /**
     * @brief Connect to MQTT message queue server.
     */
    virtual void connect();

    /**
     * @return Return true when connected to the MQTT message queue server or else `false.
     */
    [[nodiscard]] virtual bool is_connected() const;

    /**
     * @return MQTT message queue server hostname.
     */
    [[nodiscard]] virtual std::string hostname() const { return _hostname; }

    /**
     * @return MQTT message queue server port.
     */
    [[nodiscard]] virtual uint16_t port() const { return _port; }

    /**
     * @return MQTT message queue topic name for relative humidity.
     */
    [[nodiscard]] virtual std::string relative_humidity_topic() const { return _relative_humidity_topic; }

    /**
     * @return MQTT message queue topic name for temperature.
     */
    [[nodiscard]] virtual std::string temperature_topic() const { return _temperature_topic; }

    /**
     * @return MQTT message queue server username.
     */
    [[nodiscard]] virtual std::string username() const { return _username; }

    /**
     * @brief Publish a given relative humidity value on the MQTT message queue topic for relative humidity.
     * @param relative_humidity The relative humidity value to publish.
     */
    void publish_relative_humidity(float relative_humidity) override;

    /**
     * @brief Publish a given temperature value on the MQTT message queue topic for temperature.
     * @param temperature The temperature value to publish.
     */
    void publish_temperature(float temperature) override;

    /**
     * @brief Initialize (setup) the mqtt message queue.
     */
    virtual void setup();

private:

    AsyncMqttClient _client;
    std::string _hostname;
    std::string _password;
    uint16_t _port;
    std::string _relative_humidity_topic;
    std::string _temperature_topic;
    std::string _username;
};

#endif // DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_H
