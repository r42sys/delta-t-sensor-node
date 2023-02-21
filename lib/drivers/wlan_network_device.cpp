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

#include "wlan_network_device.h"

WLANNetworkDevice::WLANNetworkDevice(WLANNetworkDeviceConfigurator &configurator)
    : _passphrase(configurator.wlan_passphrase()), _ssid(configurator.wlan_ssid()), _wifi(WiFi)
{
}

void WLANNetworkDevice::connect() {
    _wifi.begin(_ssid.c_str(), _passphrase.c_str());
    while (_wifi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

bool WLANNetworkDevice::is_connected() const {
    return _wifi.isConnected();
}

std::string WLANNetworkDevice::ip_address() const {
    return _wifi.localIP().toString().c_str();
}

std::string WLANNetworkDevice::mac_address() const {
    return _wifi.macAddress().c_str();
}

void WLANNetworkDevice::setup() {
}

std::string WLANNetworkDevice::ssid() const {
    return _ssid;
}
