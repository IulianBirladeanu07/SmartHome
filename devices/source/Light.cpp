#include <iostream>
#include "Light.hpp"

Light::Light() : isLightOn(false), brightness(0) {}

void Light::on() {
    std::lock_guard<std::mutex> lock(lightMutex);
    if(!isLightOn) {
        isLightOn = true;
        brightness = 100;
        std::cout << "Light was set to ON (100%)" << std::endl;
    } else {
        std::cout << "Light is already set to ON" << std::endl;
    }
}

void Light::off() {
    std::lock_guard<std::mutex> lock(lightMutex);
    if(isLightOn) {
        isLightOn = false;
        brightness = 0;
        std::cout << "Light was set to OFF" << std::endl;
    } else {
        std::cout << "Light is already set to OFF" << std::endl;
    }
}

void Light::dim(int level) {
    std::lock_guard<std::mutex> lock(lightMutex);
    if (level >= 0 && level <= 100) {
        brightness = level;
        isLightOn = (level > 0);
        std::cout << "Light brightness set to: " << level << "%" << std::endl;
    } else {
        std::cout << "Invalid brightness level (must be 0-100)" << std::endl;
    }
}

int Light::getBrightness() {
    std::lock_guard<std::mutex> lock(lightMutex);
    return brightness;
}