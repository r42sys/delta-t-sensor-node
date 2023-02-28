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

#include <publish_sensor_data_action.h>
#include "publish_sensor_data_controller.h"
#include "publish_sensor_data_interactor.h"
#include "publish_sensor_data_presenter.h"
#include "publish_sensor_data_sensor.h"
#include "publish_sensor_data_view.h"

void PublishSensorDataAction::execute(PublishSensorDataDisplay &display, PublishSensorDataSensor &sensor, PublishSensorDataMessageQueue &message_queue) {
    PublishSensorDataView view(display);
    PublishSensorDataPresenter presenter(view);
    PublishSensorDataInteractor interactor(presenter, sensor, message_queue);
    PublishSensorDataController controller(interactor);
    controller.execute();
}
