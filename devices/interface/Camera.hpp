#include <mutex>

class Camera {
    private:
        bool recording;
        std::mutex cameraMutex;
    public:
        bool isRecording();
        void stopRecording();
        void startRecording();

        Camera();
};