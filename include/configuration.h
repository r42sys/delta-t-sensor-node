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

#ifndef DELTA_T_SENSOR_NODE_CONFIGURATION_H
#define DELTA_T_SENSOR_NODE_CONFIGURATION_H

#include <cinttypes>
#include <string>

/**
 * @brief This class is an adapter to configuration value containers, e.g. databases, ini-files, NVM, ... .
 *
 * The actual implementation uses a ESP8266 filesystem implementation as storage for the configuration values.
 */
class Configuration {

public:

    //! Default constructor.
    Configuration();

    //! Default destructor.
    ~Configuration() = default;

    /**
     * Return a value for a given key or the default value when the key is not found in the configuration.
     *
     * @tparam T The value type.
     * @param key The key.
     * @param default_value The default value.
     * @return The value for the given key or the default value when the key is not found in the configuration.
     */
    template <typename T> T value(const char *key, const T &default_value);

private:

    std::string _name;
};

#endif // DELTA_T_SENSOR_NODE_CONFIGURATION_H
