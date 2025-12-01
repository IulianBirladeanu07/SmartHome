#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <mutex>
#include <memory>
#include <vector>

#include "Observer.hpp"
#include "SensorEvent.hpp"

class Subject {
    protected:
        std::vector<Observer*> observers;
        mutable std::mutex observersMutex;

    public:
        virtual ~Subject() = default;

        void attach(Observer* observer);
        void detach(Observer* observer);
        void notifyAll(SensorEvent event);
};

#endif // SUBJECT_HPP