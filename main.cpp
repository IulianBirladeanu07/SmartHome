#include <iostream>
#include <algorithm>

#include "DeviceFactory.hpp"
#include "NestFactory.hpp"
#include "LIFXFactory.hpp"
#include "RingFactory.hpp"
#include "PhilipsFactory.hpp"

#include "HomeController.hpp"

int main() {
    HomeController& home = HomeController::getInstance();
    PhilipsFactory philips;
    NestFactory nest;
    LIFXFactory lifx;
    RingFactory ring;

    auto registerIfValid = [&home](auto device){
        if(device) home.registerDevice(device);
    };

    registerIfValid(philips.createDevice(DeviceType::LIGHT));
    registerIfValid(philips.createDevice(DeviceType::CAMERA));

    registerIfValid(nest.createDevice(DeviceType::THERMOSTAT));
    registerIfValid(nest.createDevice(DeviceType::CAMERA));

    registerIfValid(ring.createDevice(DeviceType::DOOR_LOCK));
    registerIfValid(ring.createDevice(DeviceType::CAMERA));

    registerIfValid(lifx.createDevice(DeviceType::LIGHT));
    home.listAllDevices();

    return 0;
}