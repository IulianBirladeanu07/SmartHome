#ifndef REMOTE_CONTROLLER_HPP
#define REMOTE_CONTROLLER_HPP

#include <memory>
#include <vector>

#include "Command.hpp"

class RemoteController {
    private:
        std::vector<std::shared_ptr<Command>> commands;
        std::shared_ptr<Command> lastCommand;

    public:
        RemoteController();

        void setCommand(int slotNumber, std::shared_ptr<Command> command);
        void pressCommandButton(int slotNumber);
        void pressUndoButton();

};

#endif // REMOTE_CONTROLLER_HPP