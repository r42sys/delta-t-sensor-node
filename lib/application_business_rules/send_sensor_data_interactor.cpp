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

#include "send_sensor_data_interactor.h"

SendSensorDataInteractor::SendSensorDataInteractor(SendSensorDataOutputBoundary &presenter, SendSensorDataSensor &sensor, SendSensorDataMessageQueue &message_queue)
    : _message_queue(message_queue), _presenter(presenter), _sensor(sensor)
{};

void
SendSensorDataInteractor::execute(SendSensorDataRequest &request) {
    float relative_humidity = _sensor.relative_humidity();
    float temperature = _sensor.temperature();

    _message_queue.publish_relative_humidity(relative_humidity);
    _message_queue.publish_temperature(temperature);

    SendSensorDataResponse response = {
        .relative_humidity = relative_humidity,
        .temperature = temperature
    };
    _presenter.present(response);
}
