#include <iostream>
#include <memory>
#include <algorithm>

#include "HomeController.hpp"
#include "Light.hpp"

int main() {
    HomeController& home = HomeController::getInstance();
    auto light = std::make_shared<Light>("True Light", "Phillips", DeviceType::LIGHT);
    
    HomeController::getInstance().registerDevice(light);
   
    std::cout << "Program Started!\n";
    return 0;
}