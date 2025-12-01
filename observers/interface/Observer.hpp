#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void update(const std::string& event) = 0;
};

#endif // OBSERVER_HPP