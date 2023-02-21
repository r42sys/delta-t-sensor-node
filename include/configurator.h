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

#ifndef DELTA_T_SENSOR_NODE_CONFIGURATOR_H
#define DELTA_T_SENSOR_NODE_CONFIGURATOR_H

#include <cinttypes>
#include <string>

#include "configuration.h"
#include "dht22_sensor_configurator.h"
#include "mqtt_message_queue_configurator.h"
#include "serial_line_configurator.h"
#include "ssd1306_display_configurator.h"
#include "wlan_network_device_configurator.h"

/**
 * @brief This class implements base configurator interfaces.
 */
class Configurator : public DHT22SensorConfigurator, public MQTTMessageQueueConfigurator, public SerialLineConfigurator, public SSD1306DisplayConfigurator, public WLANNetworkDeviceConfigurator {
public:

    /**
     * @param configuration The facade used to access configuration values.
     */
    explicit Configurator(Configuration &configuration);

    /**
     * @return DHT22 sensor data pin.
     */
    uint8_t dht22_data_pin() override;

    /**
     * @return Main loop delay in milliseconds.
     */
    uint32_t main_loop_delay();

    /**
     * @return MQTT hostname.
     */
    std::string mqtt_hostname() override;

    /**
     * @return MQTT password.
     */
    std::string mqtt_password() override;

    /**
     * @return MQTT port.
     */
    uint16_t mqtt_port() override;

    /**
     * @return MQTT user.
     */
    std::string mqtt_username() override;

    /**
     * @return Serial line speed in bits per second (baud).
     */
    uint32_t serial_line_speed() override;

    /**
     * @return Adafruit SSD1306 display height in pixel.
     */
    uint16_t ssd1306_height() override;

    /**
     * @return Adafruit SSD1306 display width in pixel.
     */
    uint16_t ssd1306_width() override;

    /**
     * @return WLAN passphrase.
     */
    std::string wlan_passphrase() override;

    /**
     * @return WLAN SSID.
     */
    std::string wlan_ssid() override;

private:

    Configuration _configuration;
};

#endif // DELTA_T_SENSOR_NODE_CONFIGURATOR_H
