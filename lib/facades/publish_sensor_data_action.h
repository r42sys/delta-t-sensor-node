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

#ifndef DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_ACTION_H
#define DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_ACTION_H

#include "publish_sensor_data_display.h"
#include "publish_sensor_data_message_queue.h"
#include "publish_sensor_data_sensor.h"

/**
 * @brief This class is a facade to execute the "Publish Sensor Data" use case.
 */
class PublishSensorDataAction {
public:

    /**
     * @brief Execute "Publish Sensor Data" use case.
     *
     * Read relative humidity and temperature from from a given sensor, show these values on a given display
     * and send it via a given message queue to any receiver listen on it.
     *
     * @param display The display to use for output.
     * @param sensor The sensor to use.
     * @param message_queue The message queue to use to publish sensor data.
     */
    static void execute(PublishSensorDataDisplay &display, PublishSensorDataSensor &sensor, PublishSensorDataMessageQueue &message_queue);

private:
    PublishSensorDataAction() = default;
    ~PublishSensorDataAction() = default;
};

#endif // DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_ACTION_H
