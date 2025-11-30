#include <iostream>
#include "LightOnCommand.hpp"

LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) : light(light), previousBrightness(0) {
    std::cout << "LightOnCommand::constructed!" << std::endl;
}

LightOnCommand::~LightOnCommand() {
    std::cout << "LightOnCommand::destructed!" << std::endl;
}

void LightOnCommand::execute() {
    previousBrightness = light->getBrightness();
    light->on();
}

void LightOnCommand::undo() {
    light->dim(previousBrightness);
}