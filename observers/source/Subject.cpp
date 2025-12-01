#include <iostream>
#include <algorithm>
#include "Subject.hpp"

void Subject::attach(std::shared_ptr<Observer> observer) {
    std::lock_guard<std::mutex> lock(observersMutex);
    observers.push_back(observer);
    std::cout << "Observer attached!" << std::endl; 
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    std::lock_guard<std::mutex> lock(observersMutex);
    auto it = std::remove(observers.begin(), observers.end(), observer);
    if(it != observers.end()) {
        observers.erase(it, observers.end());
        std::cout << "Observer dettached" << std::endl;
    }
}

void Subject::notifyAll(const std::string& event) {
    std::lock_guard<std::mutex> lock(observersMutex);

    for(auto& observer: observers) {
        observer->update(event);
    }
}