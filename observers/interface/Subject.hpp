#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <mutex>
#include <memory>
#include <vector>

#include "Observer.hpp"

class Subject {
    protected:
        std::vector<std::shared_ptr<Observer>> observers;
        mutable std::mutex observersMutex;

    public:
        virtual ~Subject() = default;

        void attach(std::shared_ptr<Observer> observer);
        void detach(std::shared_ptr<Observer> observer);
        void notifyAll(const std::string& event);
};

#endif // SUBJECT_HPP