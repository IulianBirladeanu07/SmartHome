class Light: {
    private:
        bool isLightOn;
    
    public:
        void on();
        void off();
        void dim(int level);
        
        int getBrightness();
};