#include <iostream>
#include "RemoteController.hpp"

#define MAX_NUMER_SLOTS 10

RemoteController::RemoteController() : lastCommand(nullptr) {
    commands.resize(MAX_NUMER_SLOTS, nullptr);
}

void RemoteController::setCommand(int slotNumber, std::shared_ptr<Command> command) {
    if(slotNumber >= 0 && slotNumber < commands.size()) {
        commands[slotNumber] = command;
    }
}

void RemoteController::pressCommandButton(int slotNumber) {
    if(slotNumber >= 0 && slotNumber < commands.size() && commands[slotNumber]) {
        commands[slotNumber]->execute();
        lastCommand = commands[slotNumber];
    } else {
        std::cout << "No command in slot " << slotNumber << std::endl;
    }
}

void RemoteController::pressUndoButton() {
    if(lastCommand) {
        lastCommand->undo();
        lastCommand = nullptr;
    } else {
        std::cout << "There is no previous command!" << std::endl;
    }
}