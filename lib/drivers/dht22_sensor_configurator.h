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

#ifndef DELTA_T_SENSOR_NODE_DHT22_SENSOR_CONFIGURATOR_H
#define DELTA_T_SENSOR_NODE_DHT22_SENSOR_CONFIGURATOR_H

#include <cinttypes>

/**
 * @brief This class defines the DHT22 sensor configurator interface.
 */
class DHT22SensorConfigurator {
public:

    DHT22SensorConfigurator() = default;
    virtual ~DHT22SensorConfigurator() = default;

    /**
     * @return DHT22 sensor data pin.
     */
    virtual uint8_t dht22_data_pin() = 0;
};

#endif // DELTA_T_SENSOR_NODE_DHT22_SENSOR_CONFIGURATOR_H
