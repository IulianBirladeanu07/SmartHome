#ifndef AUTOMATION_RULE_HPP
#define AUTOMATION_RULE_HPP

#include <memory>
#include <string>

#include "Observer.hpp"
#include "Command.hpp"

class AutomationRule: public Observer {
    private:
        std::shared_ptr<Command> command;
        std::string ruleName;
    
    public:
        AutomationRule(std::shared_ptr<Command> command, const std::string& ruleName);

        void update(SensorEvent event) override;
        std::string getRuleName() const;

};

#endif // AUTOMATION_RULE_HPP