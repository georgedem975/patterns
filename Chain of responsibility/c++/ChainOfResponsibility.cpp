#include <iostream>
#include <string>

class IWorker
{
    public:
        virtual IWorker* setNextWorker(IWorker* worker) = 0;
        virtual std::string execute(std::string command) = 0;
};

class AbstractWorker : public IWorker
{
    private:
        IWorker* nextWorker;
    public:
        AbstractWorker() : nextWorker(nullptr) {}
        IWorker* setNextWorker(IWorker* worker) override;
        std::string execute(std::string command) override;
};

class Designer : public AbstractWorker
{
    public:
        std::string execute(std::string command) override;
};

class Carpenters : public AbstractWorker
{
    public:
        std::string execute(std::string command) override;
};

class FinishingWorker : public AbstractWorker
{
    public:
        std::string execute(std::string command) override;
};

void giveCommand(IWorker* worker, std::string command);

int main()
{
    Designer* designer = new Designer();
    Carpenters* carpenters = new Carpenters();
    FinishingWorker* finishingWorker = new FinishingWorker();

    designer->setNextWorker(carpenters)->setNextWorker(finishingWorker);

    giveCommand(designer, "design a house");
    giveCommand(designer, "laying a brick");
    giveCommand(designer, "glue wallpaper");

    giveCommand(designer, "conduct the transaction");
    return 0;
}

IWorker *AbstractWorker::setNextWorker(IWorker *worker)
{
    this->nextWorker = worker;
    return worker;
}

std::string AbstractWorker::execute(std::string command)
{
    if (this->nextWorker)
        return this->nextWorker->execute(command);
    return {};
}

std::string Designer::execute(std::string command)
{
    if (command == "design a house")
        return "the designer executed the command: " + command;
    return AbstractWorker::execute(command);
}

std::string Carpenters::execute(std::string command)
{
    if (command == "laying a brick")
        return "the carpenter executed the command: " + command;
    return AbstractWorker::execute(command);
}

std::string FinishingWorker::execute(std::string command)
{
    if (command == "glue wallpaper")
        return "the interior decoration worker executed the command: " + command;
    return AbstractWorker::execute(command);
}

void giveCommand(IWorker* worker, std::string command)
{
    std::string str = worker->execute(command);
    if (str.empty())
    {
        std::cout << "no one knows how to do\n";
    }
    else
    {
        std::cout << str << std::endl;
    }
}