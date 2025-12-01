#ifndef SENSOR_EVENT_HPP
#define SENSOR_EVENT_HPP

enum class SensorEvent {
    MOTION_DETECTED,
    MOTION_CLEARED,
    
    TEMPERATURE_LOW,        // < 18°C
    TEMPERATURE_HIGH,       // > 26°C
    TEMPERATURE_NORMAL,
    
    DOOR_OPENED,
    DOOR_CLOSED,
    DOOR_LOCKED,
    DOOR_UNLOCKED,
    
    NIGHT_MODE,            // 10PM-6AM
    DAY_MODE
};

#endif // SENSOR_EVENT_HPP