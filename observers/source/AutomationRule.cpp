#include <iostream>
#include "AutomationRule.hpp"

AutomationRule::AutomationRule(std::shared_ptr<Command> command, const std::string& ruleName) : command(command), ruleName(ruleName) {
    std::cout << "AutomationRule::" << ruleName << " created" << std::endl;
}

void AutomationRule::update(const std::string& event) {
    if(command) {
        command->execute();
        std::cout << "Rule " << ruleName " triggered by: " << event << std::endl;
    }
}