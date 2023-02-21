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

#ifndef DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INTERACTOR_H
#define DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INTERACTOR_H

#include "send_sensor_data_input_boundary.h"
#include "send_sensor_data_message_queue.h"
#include "send_sensor_data_output_boundary.h"
#include "send_sensor_data_request.h"
#include "send_sensor_data_sensor.h"

/**
 * @brief This class implements the "Send Sensor Data" use case interactor.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on interactors.
 */
class SendSensorDataInteractor : public SendSensorDataInputBoundary {
public:

    /**
     * @param presenter The "Send Sensor Data" presenter.
     * @param sensor The "Send Sensor Data" sensor.
     * @param message_queue The "Send Sensor Data" message queue.
     */
    explicit SendSensorDataInteractor(SendSensorDataOutputBoundary &presenter, SendSensorDataSensor &sensor, SendSensorDataMessageQueue &message_queue);

    /**
     * @brief Execute the "Send Sensor Data" use case request.
     * @param request The "Send Sensor Data" request.
     */
    void execute(SendSensorDataRequest &request) override;

private:

    SendSensorDataMessageQueue &_message_queue;
    SendSensorDataOutputBoundary &_presenter;
    SendSensorDataSensor &_sensor;
};

#endif // DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_INTERACTOR_H
