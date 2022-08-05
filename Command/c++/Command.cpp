#include <iostream>
#include <vector>
#include <stack>

class ICommand
{
    public:
        virtual void positive() = 0;
        virtual void negative() = 0;
};

class Conveyor
{
    public:
        void on();
        void off();
        void speedIncrease();
        void speedDecrease();
};

class ConveyorWorkCommand : public ICommand
{
    private:
        Conveyor* conveyor;

    public:
        ConveyorWorkCommand(Conveyor* c) : conveyor(c) {}
        void positive() override;
        void negative() override;
};

class ConveyorAdjustCommand : public ICommand
{
    private:
        Conveyor* conveyor;

    public:
        ConveyorAdjustCommand(Conveyor* c) : conveyor(c) {}
        void positive() override;
        void negative() override;
};

class Multipult
{
    private:
        std::vector<ICommand*> commands;
        std::stack<ICommand*> history;
        
    public:
        Multipult();
        void SetCommand(int button, ICommand* command);
        void pressOn(int button);
        void pressCancel();
};

int main()
{
    Conveyor* conveyor = new Conveyor();
    
    Multipult* multipult = new Multipult();
    multipult->SetCommand(0, new ConveyorWorkCommand(conveyor));
    multipult->SetCommand(1, new ConveyorAdjustCommand(conveyor));

    multipult->pressOn(0);
    multipult->pressOn(1);
    multipult->pressCancel();
    multipult->pressCancel();
    return 0;
}

void Conveyor::on()
{
    std::cout << "the pipeline is running\n";
}

void Conveyor::off()
{
    std::cout << "the conveyor is stopped\n";
}

void Conveyor::speedIncrease()
{
    std::cout << "increased conveyor speed\n";
}

void Conveyor::speedDecrease()
{
    std::cout << "reduced conveyor speed\n";
}

void ConveyorWorkCommand::positive()
{
    conveyor->on();
}

void ConveyorWorkCommand::negative()
{
    conveyor->off();
}

void ConveyorAdjustCommand::positive()
{
    conveyor->speedIncrease();
}

void ConveyorAdjustCommand::negative()
{
    conveyor->speedDecrease();
}

Multipult::Multipult()
{
    commands.resize(2);
}

void Multipult::SetCommand(int button, ICommand *command)
{
    commands[button] = command;
}

void Multipult::pressOn(int button)
{
    commands[button]->positive();
    history.push(commands[button]);
}

void Multipult::pressCancel()
{
    if (!history.empty())
    {
        history.top()->negative();
        history.pop();
    }
}