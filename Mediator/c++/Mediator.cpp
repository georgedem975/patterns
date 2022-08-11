#include <iostream>
#include <string>

class Employee;

class Mediator
{
    public:
        virtual void notify(Employee* employee, std::string msg) = 0;
};

class Employee
{
    protected:
        Mediator* mediator;

    public:
        Employee(Mediator* med = nullptr) : mediator(med) {}
        void SetMediator(Mediator* mediator);
        virtual ~Employee() {}
};

class Designer : public Employee
{
    private:
        bool isWorking;

    public:
        Designer(Mediator* mediator = nullptr) : Employee(mediator) {}
        void executeWork();
        void SetWork(bool state);
};

class Director : public Employee
{
    private:
        std::string text;

    public:
        Director(Mediator* mediator = nullptr) : Employee(mediator) {}
        void giveCommand(std::string txt);
};

class Controller : public Mediator
{
    private:
        Designer* designer;
        Director* director;
    
    public:
        Controller(Designer* designer, Director* director);
        void notify(Employee* employee, std::string msg);
};

int main()
{
    Designer* designer = new Designer();
    Director* director = new Director();

    Controller* mediator = new Controller(designer, director);

    director->giveCommand("design");

    std::cout << std::endl;

    designer->executeWork();

    delete designer;
    delete director;
    delete mediator;
    
    return 0;
}

void Employee::SetMediator(Mediator *mediator)
{
    this->mediator = mediator;
}

void Designer::executeWork()
{
    std::cout << "<-the designer is at work\n";
    mediator->notify(this, "the designer designs...");
}

void Designer::SetWork(bool state)
{
    isWorking = state;
    if (state)
        std::cout << "<-the designer is released from work\n";
    else
        std::cout << "<-the designer is busy\n";
}

void Director::giveCommand(std::string txt)
{
    text = txt;
    if (text.empty())
        std::cout << "->the director knows that the designer is already working\n";
    else
        std::cout << "->the director gave the command: " << text << std::endl;
    mediator->notify(this, text);
}

Controller::Controller(Designer *designer, Director *director)
{
    this->director = director;
    this->designer = designer;
    designer->SetMediator(this);
    director->SetMediator(this);
}

void Controller::notify(Employee *employee, std::string msg)
{
    if (auto dir = dynamic_cast<Director*>(employee))
    {
        if (msg.empty())
            designer->SetWork(false);
        else
            designer->SetWork(true);
    }
    if (auto des = dynamic_cast<Designer*>(employee))
        if (msg == "the designer designs...")
            director->giveCommand("");
}