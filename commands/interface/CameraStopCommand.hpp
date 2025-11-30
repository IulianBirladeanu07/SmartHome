#include "../devices/Camera.hpp"
#include "Command.hpp"

class CameraStopCommand: public Command {
    private:
        std::shared_ptr<Camera> camera;

    public:
        void execute() override;
        void undo() override;

        ~CameraStopCommand();
};
