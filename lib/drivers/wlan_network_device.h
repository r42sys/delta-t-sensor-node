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

#ifndef DELTA_T_SENSOR_NODE_WLAN_NETWORK_DEVICE_H
#define DELTA_T_SENSOR_NODE_WLAN_NETWORK_DEVICE_H

#include <string>

#include <ESP8266WiFi.h>

#include "wlan_network_device_configurator.h"

/**
 * @brief This class implements a WLAN network device.
 */
class WLANNetworkDevice {
public:

    /**
     * @param configurator The WLAN network device configurator.
     */
    explicit WLANNetworkDevice(WLANNetworkDeviceConfigurator &configurator);
    virtual ~WLANNetworkDevice() = default;

    /**
     * @brief Connect WLAN network device to WLAN.
     */
    virtual void connect();

    /**
     * Return true when the WLAN network device is connected to WLAN or else false.
     * @return True when the WLAN network device is connected to WLAN or else false.
     */
    [[nodiscard]] virtual bool is_connected() const;

    /**
     * Return WLAN network device's IP address.
     * @return WLAN network device's IP address.
     */
    [[nodiscard]] virtual std::string ip_address() const;

    /**
     * Return WLAN network device's MAC address.
     * @return WLAN network device's MAC address.
     */
    [[nodiscard]] virtual std::string mac_address() const;

    /**
     * @brief Initialize (setup) the WLAN network device's hardware.
     */
    virtual void setup();

    /**
     * Return WLAN network device's SSID.
     * @return WLAN network device's SSID.
     */
    [[nodiscard]] virtual std::string ssid() const;

private:

    std::string _passphrase;
    std::string _ssid;
    ESP8266WiFiClass &_wifi;
};


#endif // DELTA_T_SENSOR_NODE_WLAN_NETWORK_DEVICE_H
