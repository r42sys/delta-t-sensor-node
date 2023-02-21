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

#include <map>

#include <Wire.h>

#include "ssd1306_display.h"


SSD1306Display::SSD1306Display(SSD1306DisplayConfigurator &configurator)
    : _ssd1306(configurator.ssd1306_width(), configurator.ssd1306_height(), &Wire)
{
}

SSD1306Display::SSD1306Display(uint16_t width, uint16_t height)
    : _ssd1306(width, height, &Wire)
{
}

void SSD1306Display::clear() {
    _ssd1306.clearDisplay();
    _ssd1306.setCursor(0, 0);
}

uint16_t SSD1306Display::height() const {
    return _ssd1306.height();
}

size_t SSD1306Display::print(const char *s) {
    return _ssd1306.print(s);
}

size_t SSD1306Display::print(const std::string &s) {
    return print(s.c_str());
}

size_t SSD1306Display::println(const char *s) {
    return _ssd1306.println(s);
}

size_t SSD1306Display::println(const std::string &s) {
    return println(s.c_str());
}

void SSD1306Display::setup() {
    _ssd1306.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    _ssd1306.display();
    delay(1000);

    _ssd1306.clearDisplay();
    _ssd1306.display();

    _ssd1306.setTextSize(1);
    _ssd1306.setTextColor(SSD1306_WHITE);
    _ssd1306.setCursor(0, 0);
}

void SSD1306Display::update() {
    _ssd1306.display();
}

uint16_t SSD1306Display::width() const {
    return _ssd1306.width();
}

