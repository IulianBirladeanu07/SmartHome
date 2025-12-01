#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <mutex>
#include <string>

#include "Device.hpp"

class Camera: public Device {
    private:
        bool recording;
        mutable std::mutex cameraMutex;
    public:
        Camera(const std::string& name, const std::string& manufacturer, DeviceType type);

        bool isRecording();
        void stopRecording();
        void startRecording();

        std::string getStatus() const override;
};

#endif // CAMERA_HPP