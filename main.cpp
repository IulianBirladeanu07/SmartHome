#include <iostream>
#include <algorithm>

#include "DeviceFactory.hpp"
#include "PhilipsFactory.hpp"
#include "HomeController.hpp"

int main() {
    HomeController& home = HomeController::getInstance();
    PhilipsFactory philips;
    
    auto light = philips.createDevice(DeviceType::LIGHT);
    auto thermostat = philips.createDevice(DeviceType::THERMOSTAT);
    
    if(light) {
        home.registerDevice(light);
    } 
    else if(thermostat) {
        home.registerDevice(thermostat);
    }
    
    home.listAllDevices();

    return 0;
}