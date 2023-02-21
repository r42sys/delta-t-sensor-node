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

#include <iomanip>
#include <sstream>

#include "send_sensor_data_presenter.h"

SendSensorDataPresenter::SendSensorDataPresenter(SendSensorDataView &view)
    : _view(view)
{}

void SendSensorDataPresenter::present(SendSensorDataResponse &response) {
    std::stringstream relative_humidity;
    relative_humidity << std::fixed << std::setprecision(1) << response.relative_humidity;

    std::stringstream temperature;
    temperature << std::fixed << std::setprecision(1) << response.temperature;

    SendSensorDataViewModel view_model = {
        .relative_humidity = relative_humidity.str(),
        .temperature = temperature.str()
    };
    _view.render(view_model);
}
