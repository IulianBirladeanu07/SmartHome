#include <iostream>
#include <algorithm>

#include "DeviceFactory.hpp"
#include "NestFactory.hpp"
#include "LIFXFactory.hpp"
#include "RingFactory.hpp"
#include "PhilipsFactory.hpp"

#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "LightDimCommand.hpp"
#include "CameraStartCommand.hpp"
#include "CameraStopCommand.hpp"
#include "DoorLockCommand.hpp"
#include "DoorUnlockCommand.hpp"
#include "ThermostatSetCommand.hpp"

#include "HomeController.hpp"
#include "RemoteController.hpp"

#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5
#define BUTTON_6 6
#define BUTTON_7 7
#define BUTTON_8 8
#define BUTTON_9 9

#define DEFAULT_TEMP 20 // degrees C
#define DEFAULT_BRIGHTNESS 80 // 80%

int main() {
    HomeController& home = HomeController::getInstance();
    PhilipsFactory philips;
    NestFactory nest;
    LIFXFactory lifx;
    RingFactory ring;

    auto ringCamera = std::dynamic_pointer_cast<Camera>
                        (ring.createDevice(DeviceType::CAMERA));

    auto ringDoor = std::dynamic_pointer_cast<DoorLock>
                        (ring.createDevice(DeviceType::DOOR_LOCK));
                        
    auto philipsLight = std::dynamic_pointer_cast<Light>
                        (philips.createDevice(DeviceType::LIGHT));
    
    auto nestThermostat = std::dynamic_pointer_cast<Thermostat>
                        (nest.createDevice(DeviceType::THERMOSTAT));

    auto lightOnCommand = std::make_shared<LightOnCommand>(philipsLight);
    auto lightOffCommand = std::make_shared<LightOffCommand>(philipsLight);
    auto lightDimCommand = std::make_shared<LightDimCommand>(philipsLight, DEFAULT_BRIGHTNESS);

    auto cameraStopCommand = std::make_shared<CameraStopCommand>(ringCamera);
    auto cameraStartCommand = std::make_shared<CameraStartCommand>(ringCamera);

    auto doorLockCommand = std::make_shared<DoorLockCommand>(ringDoor);
    auto doorUnlockCommand = std::make_shared<DoorUnlockCommand>(ringDoor);
    auto thermostatSetCommand = std::make_shared<ThermostatSetCommand>(nestThermostat, DEFAULT_TEMP);

    auto registerIfValid = [&home](auto device){
        if(device) home.registerDevice(device);
    };

    registerIfValid(ringCamera);
    registerIfValid(ringDoor);
    registerIfValid(philipsLight);
    registerIfValid(nestThermostat);

    RemoteController remote;
    remote.setCommand(BUTTON_0, lightOnCommand);
    remote.setCommand(BUTTON_1, lightOffCommand);
    remote.setCommand(BUTTON_2, lightDimCommand);
    remote.setCommand(BUTTON_3, cameraStartCommand);
    remote.setCommand(BUTTON_4, cameraStopCommand);
    remote.setCommand(BUTTON_5, doorLockCommand);
    remote.setCommand(BUTTON_6, doorUnlockCommand);
    remote.setCommand(BUTTON_7, thermostatSetCommand);

    remote.pressCommandButton(BUTTON_0);
    home.listAllDevices();

    return 0;
}