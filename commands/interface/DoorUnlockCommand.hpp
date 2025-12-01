#ifndef DOOR_UNLOCK_COMMAND_HPP
#define DOOR_UNLOCK_COMMAND_HPP

#include <memory>

#include "DoorLock.hpp"
#include "Command.hpp"

class DoorUnlockCommand: public Command {
    private:
        bool previousState;
        std::shared_ptr<DoorLock> doorLock;
    
    public:
        void execute() override;
        void undo() override;

        DoorUnlockCommand(std::shared_ptr<DoorLock> doorLock);
        ~DoorUnlockCommand();
};

#endif // DOOR_UNLOCK_COMMAND_HPP