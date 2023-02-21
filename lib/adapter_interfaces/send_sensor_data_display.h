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

#ifndef DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_DISPLAY_H
#define DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_DISPLAY_H

#include <string>

/**
 * @brief This class defines the display interface for the "Send Sensor Data" use case.
 */
class SendSensorDataDisplay {
public:

    virtual ~SendSensorDataDisplay() = default;

    /**
     * @brief Clear the display and set cursor to (0, 0) position. The display is not updated unless the
     * update() member function is called.
     */
    virtual void clear() = 0;

    /**
     * @brief Print a given string on the display at actual cursor position. The display is not updated unless the
     * update() member function is called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    virtual size_t print(const char *s) = 0;

    /**
     * @brief Print a given string on the display at actual cursor position. The display is not updated unless the
     * update() member function is called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    virtual size_t print(const std::string &s) = 0;

    /**
     * @brief Print a given string followed by a newline on the display at actual cursor position. The display is not
     * updated unless the update() member function is called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    virtual size_t println(const char *s) = 0;

    /**
     * @brief Print a given string followed by a newline on display at actual cursor position. The display is not
     * updated unless the update() member function is called.
     *
     * @param s The string to print.
     * @return Number of characters printed.
     */
    virtual size_t println(const std::string &s) = 0;

    /**
     * @brief Update the display.
     */
    virtual void update() = 0;
};

#endif // DELTA_T_SENSOR_NODE_SEND_SENSOR_DATA_DISPLAY_H
