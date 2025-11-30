#include <iostream>
#include "LightOffCommand.hpp"

LightOffCommand::LightOffCommand(std::shared_ptr<Light> light) : light(light), previousBrightness(0) {
    std::cout << "LightOffCommand::constructed!" << std::endl;
}

LightOffCommand::~LightOffCommand() {
    std::cout << "LightOffCommand::destructed!" << std::endl;
}

void LightOffCommand::execute() {
    previousBrightness = light->getBrightness();
    light->off();
}

void LightOffCommand::undo() {
    light->dim(previousBrightness);
}