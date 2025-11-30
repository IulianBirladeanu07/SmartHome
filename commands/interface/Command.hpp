class Command {
    public:
        virtual void execute();
        virtual void undo();
        virtual ~Command();

};