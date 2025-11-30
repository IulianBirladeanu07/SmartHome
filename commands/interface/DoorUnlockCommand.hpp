#include "../devices/DoorLock.hpp"
#include "Command.hpp"

class DoorUnlockCommand: public Command {
    private:
        std::shared_ptr<DoorLock> doorLock;
    
    public:
        void execute() override;
        void undo() override;

        DoorUnlockCommand();
        ~DoorUnlockCommand();
};