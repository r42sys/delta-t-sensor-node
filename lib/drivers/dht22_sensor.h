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

#ifndef DELTA_T_SENSOR_NODE_DHT22_SENSOR_H
#define DELTA_T_SENSOR_NODE_DHT22_SENSOR_H

#include <cinttypes>

#include <DHT.h>

#include "dht22_sensor_configurator.h"
#include "sensor_gateway.h"

/**
 * @brief This class implements the sensor gateway interface for a DHT22 sensor.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on gateways.
 */
class DHT22Sensor : public SensorGateway {
public:

    /**
     * @param configurator The DHT22 sensor configurator.
     */
    explicit DHT22Sensor(DHT22SensorConfigurator &configurator);

    /**
     * @param data_pin The data data_pin of the DHT22 sensor.
     */
    explicit DHT22Sensor(uint8_t data_pin);

    /**
     * Read the actual relative humidity [%] from DHT22 sensor.
     * @return The actual relative humidity [%}.
     */
    float relative_humidity() override;

    /**
     * Read the actual temperature [°C] from DHT22 sensor.
     * @return The actual temperature [°C].
     */
    float temperature() override;

    /**
     * @brief Initialize (setup) the DHT22 sensor hardware.
     */
    virtual void setup();

private:

    DHT _dht;
};

#endif // DELTA_T_SENSOR_NODE_DHT22_SENSOR_H
