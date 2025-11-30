class Camera: {
    private:
        bool recording;

    public:
        bool isRecording();
        void stopRecording();
        void startRecording();
};