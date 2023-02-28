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

#ifndef DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_MESSAGE_QUEUE_H
#define DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_MESSAGE_QUEUE_H

/**
 * @brief This class defines the message queue interface for the "Send Sensor Data" use case.
 */
class SendSensorDataMessageQueue {
public:

    virtual ~SendSensorDataMessageQueue() = default;

    /**
     * Publish a give relative humidity.
     *
     * @param relative_humidity The relative humidity.
     */
    virtual void publish_relative_humidity(float relative_humidity) = 0;

    /**
     * Publish a given temperature.
     *
     * @param temperature The temperature.
     */
    virtual void publish_temperature(float temperature) = 0;
};


#endif // DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_MESSAGE_QUEUE_H
