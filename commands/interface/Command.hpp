#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
    public:
        virtual void execute();
        virtual void undo();
        virtual ~Command();

};

#endif // COMMAND_HPP