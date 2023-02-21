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

#ifndef DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INPUT_BOUNDARY_H
#define DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INPUT_BOUNDARY_H

#include <send_sensor_data_request.h>

/**
 * @brief This class defines the "Send Sensor Data" use case input boundary.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on input
 * boundaries.
 */
class SendSensorDataInputBoundary {
public:

    virtual ~SendSensorDataInputBoundary() = default;

    /**
     * @brief Execute the "Send Sensor Data" use case request.
     * @param request The "Send Sensor Data" request.
     */
    virtual void execute(SendSensorDataRequest &request) = 0;
};

#endif // DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INPUT_BOUNDARY_H
