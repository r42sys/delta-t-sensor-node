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

#ifndef DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_CONFIGURATOR_H
#define DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_CONFIGURATOR_H

#include <cinttypes>
#include <string>

/**
 * @brief This class defines the MQTT message queue configurator interface.
 */
class MQTTMessageQueueConfigurator {
public:

    virtual ~MQTTMessageQueueConfigurator() = default;

    /**
     * @return MQTT hostname.
     */
    virtual std::string mqtt_hostname() = 0;

    /**
     * @return MQTT password.
     */
    virtual std::string mqtt_password() = 0;

    /**
     * @return MQTT port.
     */
    virtual uint16_t mqtt_port() = 0;

    /**
     * @return MQTT user.
     */
    virtual std::string mqtt_username() = 0;
};

#endif // DELTA_T_SENSOR_NODE_MQTT_MESSAGE_QUEUE_CONFIGURATOR_H
