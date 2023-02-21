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

#ifndef DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_VIEW_H
#define DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_VIEW_H

#include "send_sensor_data_display.h"
#include "send_sensor_data_view_model.h"

/**
 * @brief This class implements a view for the "Send Sensor Data" use case.
*
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on views.
  */
class SendSensorDataView {
public:

    /**
     * @param display The display to used to render the view model.
     */
    explicit SendSensorDataView(SendSensorDataDisplay &display);

    /**
     * @brief Render the "Send Sensor Data" view model on a display.
     *
     * @param view_model The view model to render.
     */
    virtual void render(SendSensorDataViewModel &view_model);

private:

    SendSensorDataDisplay &_display;
};

#endif // DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_VIEW_H
