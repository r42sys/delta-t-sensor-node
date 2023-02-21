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

#include <Preferences.h>

#include "configuration.h"


Configuration::Configuration()
    : _name()
{}

/**
 * Return a value for a given key or the default value when the key is not found in the configuration.
 *
 * Specialization of Configuration::value() for uint8_t.
 *
 * @tparam T The value type.
 * @param key The key.
 * @param default_value The default value.
 * @return The value for the given key or the default value when the key is not found in the configuration.
 */
template<>
uint8_t Configuration::value<uint8_t>(const char *key, const uint8_t &default_value) {
    Preferences preferences;
    preferences.begin(_name.c_str());
    uint8_t value = preferences.getUChar(key, default_value);
    preferences.end();
    return value;
}

/**
 * Return a value for a given key or the default value when the key is not found in the configuration.
 *
 * Specialization of Configuration::value() for uint16_t.
 *
 * @param key The key.
 * @param default_value The default value.
 * @return The value for the given key or the default value when the key is not found in the configuration.
 */
template<>
uint16_t Configuration::value<uint16_t>(const char *key, const uint16_t &default_value) {
    Preferences preferences;
    preferences.begin(_name.c_str());
    uint16_t value = preferences.getUShort(key, default_value);
    preferences.end();
    return value;
}

/**
 * Return a value for a given key or the default value when the key is not found in the configuration.
 *
 * Specialization of Configuration::value() for uint32_t.
 *
 * @param key The key.
 * @param default_value The default value.
 * @return The value for the given key or the default value when the key is not found in the configuration.
 */
template<>
uint32_t Configuration::value<uint32_t>(const char *key, const uint32_t &default_value) {
    Preferences preferences;
    preferences.begin(_name.c_str());
    uint32_t value = preferences.getULong(key, default_value);
    preferences.end();
    return value;
}

/**
 * Return a value for a given key or the default value when the key is not found in the configuration.
 *
 * Specialization of Configuration::value() for uint64_t.
 *
 * @param key The key.
 * @param default_value The default value.
 * @return The value for the given key or the default value when the key is not found in the configuration.
 */
template<>
uint64_t Configuration::value<uint64_t>(const char *key, const uint64_t &default_value) {
    Preferences preferences;
    preferences.begin(_name.c_str());
    uint64_t value = preferences.getULong64(key, default_value);
    preferences.end();
    return value;
}

/**
 * Return a value for a given key or the default value when the key is not found in the configuration.
 *
 * Specialization of Configuration::value() for std::string.
 *
 * @param key The key.
 * @param default_value The default value.
 * @return The value for the given key or the default value when the key is not found in the configuration.
 */
template<>
std::string Configuration::value<std::string>(const char *key, const std::string &default_value) {
    Preferences preferences;
    preferences.begin(_name.c_str());
    std::string value = preferences.getString(key, default_value.c_str()).c_str();
    preferences.end();
    return value;
}
