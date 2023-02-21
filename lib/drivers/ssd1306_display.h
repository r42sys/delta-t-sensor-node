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

#ifndef DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_H
#define DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_H

#include <cinttypes>

#include <Adafruit_SSD1306.h>

#include "display_gateway.h"
#include "ssd1306_display_configurator.h"
#include "ssd1306_display.h"

/**
 * @brief This class implements the display gateway interface for an Adafruit SSD1306 OLED display.
 *
 * Please checkout [clean architecture](https://github.com/r42sys/clean-architecture) for more details on gateways.
 */
class SSD1306Display : public DisplayGateway {
public:

    /**
     * @param configurator The Adafruit SSD1306 OLED display configurator.
     */
    explicit SSD1306Display(SSD1306DisplayConfigurator &configurator);

    /**
     * @param width The width of the Adafruit SSD1306 OLED display in pixels.
     * @param height The height of the Adafruit SSD1306 OLED display in pixels.
     */
    explicit SSD1306Display(uint16_t width=128, uint16_t height=32);

    /**
     * @brief Clear the Adafruit SSD1306 OLED display and set cursor to (0, 0) position.
     *
     * To show the cleared display the update() function has to be called.
     */
    void clear() override;

    /**
     * @return The Adafruit SSD1306 OLED display height.
     */
    [[nodiscard]] virtual uint16_t height() const;

    /**
     * @brief Print a given string on the Adafruit SSD1306 OLED display at actual cursor position.
     *
     * When a mapping of the given string to flash memory string exists the mapped string is printed instead of the
     * given one.
     *
     * To show the printed string the update() function has to be called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    size_t print(const char *s) override;

    /**
     * @brief Print a given string on the Adafruit SSD1306 OLED display at actual cursor position.
     *
     * When a mapping of the given string to flash memory string exists the mapped string is printed instead of the
     * given one.
     *
     * To show the printed string the update() function has to be called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    size_t print(const std::string &s) override;

    /**
     * @brief Print a given string followed by a newline on the Adafruit SSD1306 OLED display at actual cursor position.
     *
     * When a mapping of the given string to flash memory string exists the mapped string is printed instead of the
     * given one.
     *
     * To show the printed string the update() function has to be called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    size_t println(const char *s) override;

    /**
     * @brief Print a given string followed by a newline on the Adafruit SSD1306 OLED display at actual cursor position.
     *
     * When a mapping of the given string to flash memory string exists the mapped string is printed instead of the
     * given one.
     *
     * To show the printed string the update() function has to be called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    size_t println(const std::string &s) override;

    /**
     * @brief Update the Adafruit SSD1306 OLED display.
     *
     * This has function has to be called after something has printed to the display or the display has been cleared
     * to make the changed visible to the user.
     */
    void update() override;

    /**
     * @brief Initialize (setup) the Adafruit SSD1306 OLED display hardware.
     */
    virtual void setup();

    /**
     * @return The Adafruit SSD1306 OLED display width.
     */
    [[nodiscard]] virtual uint16_t width() const;

private:

    Adafruit_SSD1306 _ssd1306;
};

#endif // DELTA_T_SENSOR_NODE_SSD1306_DISPLAY_H
