class DoorLock {
    private:
        bool locked;
        std::mutex doorMutex;

    public:
        void lock();
        void unlock();
        bool isLocked();

        DoorLock();
};