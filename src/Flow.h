class Flow{
    private:
        IExecutable* commands[];

    public:
        Flow(map<string, IExecutable*> commands;)
        void run();
}