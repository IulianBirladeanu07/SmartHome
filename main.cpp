#include <iostream>
#include <memory>
#include <algorithm>

#include "HomeController.hpp"
#include "Thermostat.hpp"
#include "Light.hpp"

int main() {
    HomeController& home = HomeController::getInstance();
    
    auto light = std::make_shared<Light>("Light", "Phillips", DeviceType::LIGHT);
    auto thermostat = std::make_shared<Thermostat>("Thermostat", "LEAP", DeviceType::THERMOSTAT);
    
    home.registerDevice(light);
    home.registerDevice(thermostat);
    
    home.listAllDevices();

    return 0;
}