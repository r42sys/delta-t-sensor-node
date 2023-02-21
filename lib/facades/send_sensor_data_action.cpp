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

#include <send_sensor_data_action.h>
#include "send_sensor_data_controller.h"
#include "send_sensor_data_interactor.h"
#include "send_sensor_data_presenter.h"
#include "send_sensor_data_sensor.h"
#include "send_sensor_data_view.h"

void SendSensorDataAction::execute(SendSensorDataDisplay &display, SendSensorDataSensor &sensor, SendSensorDataMessageQueue &message_queue) {
    SendSensorDataView view(display);
    SendSensorDataPresenter presenter(view);
    SendSensorDataInteractor interactor(presenter, sensor, message_queue);
    SendSensorDataController controller(interactor);
    controller.execute();
}
