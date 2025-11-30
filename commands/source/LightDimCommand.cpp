#include <iostream>
#include "LightDimCommand.hpp"

LightDimCommand::LightDimCommand(std::shared_ptr<Light> light, int targetBrightness) : light(light), targetBrightness(targetBrightness) {
    std::cout << "LightDimCommand::constructed!" << std::endl;
}

LightDimCommand::~LightDimCommand() {
    std::cout << "LightDimCommand::deconstructed!" << std::endl;
}

void LightDimCommand::execute() {
    previousBrightness = light->getBrightness();
    light->dim(targetBrightness);
}

void LightDimCommand::undo() {
    if(!previousBrightness) {
        light->dim(previousBrightness);
    }
}