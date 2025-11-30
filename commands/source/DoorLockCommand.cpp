#include <iostream>
#include "DoorLockCommand.hpp"

DoorLockCommand::DoorLockCommand(std::shared_ptr<DoorLock> doorLock) : doorLock(doorLock) {
    std::cout << "DoorLockCommand::constructed!" << std::endl;
}

DoorLockCommand::~DoorLockCommand() {
    std::cout << "DoorLockCommand::destructed!" << std::endl;
}

void DoorLockCommand::execute() {
    previousState = doorLock->isLocked();
    doorLock->lock();
}

void DoorLockCommand::undo() {
    if(!previousState) {
        doorLock->unlock();
    }
}