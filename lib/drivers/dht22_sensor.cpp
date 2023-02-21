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

#include "dht22_sensor.h"

DHT22Sensor::DHT22Sensor(DHT22SensorConfigurator &configurator)
    : _dht(configurator.dht22_data_pin(), DHT22)
{
}

DHT22Sensor::DHT22Sensor(uint8_t data_pin)
    : _dht(data_pin, DHT22)
{
}

float DHT22Sensor::relative_humidity() {
    return _dht.readHumidity();
}

void DHT22Sensor::setup() {
    _dht.begin();
}

float DHT22Sensor::temperature()
{
    return _dht.readTemperature();
}
