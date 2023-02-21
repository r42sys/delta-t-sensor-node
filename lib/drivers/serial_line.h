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

#ifndef DELTA_T_SENSOR_NODE_SERIAL_LINE_H
#define DELTA_T_SENSOR_NODE_SERIAL_LINE_H

#include <string>

#include <HardwareSerial.h>

#include "serial_line_configurator.h"

/**
 * @brief A class implements a serial line.
 */
class SerialLine {
public:

    /**
     * @param configurator The serial line configurator.
     */
    explicit SerialLine(SerialLineConfigurator &configurator);
    virtual ~SerialLine() = default;

    /**
     * Return true when the serial line is ready to be used or else false.
     * @return True when the serial line is ready to be used or else false.
     */
    [[nodiscard]] virtual bool is_ready() const;

    /**
     * Print a given integer value to serial line.
     * @param value The value.
     */
    virtual void print(uint16_t value);

    /**
     * Print a given string to serial line.
     * @param s The string.
     */
    virtual void print(const char *s);

    /**
     * Print a given string to serial line.
     * @param s The string.
     */
    virtual void print(const std::string &s);

    /**
     * Print a given integer value to serial line followed by a newline.
     * @param value The value.
     */
    virtual void println(uint16_t value);

    /**
     * Print a given string to serial line followed by a newline.
     * @param s The string.
     */
    virtual void println(const char *s);

    /**
     * Print a given string to serial line followed by a newline.
     * @param s The string.
     */
    virtual void println(const std::string &s);

    /**
     * @brief Initialize (setup) the serial line hardware.
     */
    virtual void setup();

private:

    HardwareSerial _serial;
    unsigned long _speed;
};


#endif // DELTA_T_SENSOR_NODE_SERIAL_LINE_H
