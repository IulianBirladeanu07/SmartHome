#include <iostream>
#include "DoorUnlockCommand.hpp"

DoorUnlockCommand::DoorUnlockCommand(std::shared_ptr<DoorLock> doorLock) : doorLock(doorLock) {
    std::cout << "DoorUnlockCommand::constructed!" << std::endl;
}

DoorUnlockCommand::~DoorUnlockCommand() {
    std::cout << "DoorUnlockCommand::destructed!" << std::endl;
}

void DoorUnlockCommand::execute() {
    previousState = doorLock->isLocked();
    doorLock->unlock();
}

void DoorUnlockCommand::undo() {
    if(previousState) {
        doorLock->lock();
    }
}