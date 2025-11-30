#include "../devices/DoorLock.hpp"
#include "Command.hpp"

class DoorLockCommand: public Command {
    private:
        std::shared_ptr<DoorLock> doorLock;
    
    public:
        void execute() override;
        void undo() override;

        DoorLockCommand();
        ~DoorLockCommand();
};