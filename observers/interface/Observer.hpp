#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>
#include "SensorEvent.hpp"

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void update(SensorEvent event) = 0;
};

#endif // OBSERVER_HPP