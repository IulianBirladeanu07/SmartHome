#include <memory>

#include "DoorLock.hpp"
#include "Command.hpp"

class DoorLockCommand: public Command {
    private:
        bool previousState;
        std::shared_ptr<DoorLock> doorLock;
    
    public:
        void execute() override;
        void undo() override;

        DoorLockCommand(std::shared_ptr<DoorLock> doorLock);
        ~DoorLockCommand();
};