interface ICommand
{
    void Positive();
    void Negative();
}

class Conveyor
{
    public void On() => Console.WriteLine("the pipeline is running");

    public void Off() => Console.WriteLine("the conveyor is stopped");

    public void SpeedIncrease() => Console.WriteLine("increased conveyor speed");

    public void SpeedDecrease() => Console.WriteLine("reduced conveyor speed");
}

class ConveyorWorkCommand : ICommand
{
    private Conveyor _conveyor;

    public ConveyorWorkCommand(Conveyor conveyor) => _conveyor = conveyor;

    public void Positive() => _conveyor.On();

    public void Negative() => _conveyor.Off();
}

class ConveyorAdjustCommand : ICommand
{
    private Conveyor _conveyor;

    public ConveyorAdjustCommand(Conveyor conveyor) => _conveyor = conveyor;

    public void Positive() => _conveyor.SpeedIncrease();
    
    public void Negative() => _conveyor.SpeedDecrease();
}

class Multipult
{
    private List<ICommand?> _commands;
    private Stack<ICommand> _history;

    public Multipult()
    {
        _commands = new List<ICommand>() {null, null};
        _history = new Stack<ICommand>();
    }

    public void SetCommand(int button, ICommand command) => _commands[button] = command;

    public void PressOn(int button)
    {
        _commands[button].Positive();
        _history.Push(_commands[button]);
    }

    public void PressCancel()
    {
        if (_history.Count != 0)
            _history.Pop().Negative();
    }
}

class Program
{
    static void Main()
    {
        Conveyor conveyor = new Conveyor();

        Multipult multipult = new Multipult();
        multipult.SetCommand(0, new ConveyorWorkCommand(conveyor));
        multipult.SetCommand(1, new ConveyorAdjustCommand(conveyor));
        
        multipult.PressOn(0);
        multipult.PressOn(1);
        multipult.PressCancel();
        multipult.PressCancel();
    }
}