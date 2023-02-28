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

#include "send_sensor_data_view.h"

SendSensorDataView::SendSensorDataView(SendSensorDataDisplay &display)
    : _display(display)
{}

void SendSensorDataView::render(SendSensorDataViewModel &view_model) {
    _display.clear();
    _display.print("Temperature: ");
    _display.print(view_model.temperature);
    _display.println(" C");
    _display.print("Humidity: ");
    _display.print(view_model.relative_humidity);
    _display.println("%");
    _display.update();
}
