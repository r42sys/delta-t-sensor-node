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

#ifndef DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_VIEW_MODEL_H
#define DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_VIEW_MODEL_H

#include <string>

/**
 * @brief This data structure implements the view model for the "Publish Sensor Data" use case.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on view models.
 */
struct PublishSensorDataViewModel {

    /// Relative humidity [%].
    std::string relative_humidity;

    /// Temperature [°C].
    std::string temperature;
};

#endif // DELTA_T_SENSOR_NODE_PUBLISH_SENSOR_DATA_VIEW_MODEL_H
