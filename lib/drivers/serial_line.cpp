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

#include "serial_line.h"

SerialLine::SerialLine(SerialLineConfigurator &configurator)
    : _serial(Serial), _speed(configurator.serial_line_speed())
{
}

bool SerialLine::is_ready() const {
    return _serial;
}

void SerialLine::print(uint16_t value) {
    _serial.print(value);
}

void SerialLine::print(const char *s) {
    _serial.print(s);
}

void SerialLine::print(const std::string &s) {
    _serial.print(s.c_str());
}

void SerialLine::println(uint16_t value) {
    _serial.println(value);
}

void SerialLine::println(const char *s) {
    _serial.println(s);
}

void SerialLine::println(const std::string &s) {
    _serial.println(s.c_str());
}

void SerialLine::setup() {
    _serial.begin(_speed);
}
