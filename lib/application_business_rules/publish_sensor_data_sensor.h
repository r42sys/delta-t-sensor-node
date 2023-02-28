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

#ifndef DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_SENSOR_H
#define DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_SENSOR_H

/**
 * @brief This class defines the "Publish Sensor Data" sensor interface.
 */
class PublishSensorDataSensor {
public:

    virtual ~PublishSensorDataSensor() = default;

    /**
     * Read the actual relative humidity [%] from sensor.
     * @return The actual relative humidity [%}.
     */
    virtual float relative_humidity() = 0;

    /**
     * Read the actual temperature [°C] from sensor.
     * @return The actual temperature [°C].
     */
    virtual float temperature() = 0;
};

#endif //DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_SENSOR_H
