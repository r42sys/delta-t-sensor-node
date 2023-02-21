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

#ifndef DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_CONFIGURATOR_H
#define DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_CONFIGURATOR_H

#include <cinttypes>

/**
 * @brief This class defines the Adafruit SSD1306 OLED display configurator interface.
 */
class SSD1306DisplayConfigurator {
public:

    SSD1306DisplayConfigurator() = default;
    virtual ~SSD1306DisplayConfigurator() = default;

    /**
     * @return Adafruit SSD1306 display height in pixel.
     */
    virtual uint16_t ssd1306_height() = 0;

    /**
     * @return Adafruit SSD1306 display width in pixel.
     */
    virtual uint16_t ssd1306_width() = 0;
};

#endif // DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_CONFIGURATOR_H
