interface IMediator
{
    void Notify(Employee employee, string msg);
}

abstract class Employee
{
    protected IMediator Mediator;
    
    public Employee(IMediator mediator) => Mediator = mediator;

    public void SetMediator(IMediator mediator) => Mediator = mediator;
}

class Designer : Employee
{
    public Designer(IMediator mediator = null) : base(mediator) {}

    public void ExecuteWork()
    {
        Console.WriteLine("<-the designer is at work");
        Mediator.Notify(this, "the designer designs...");
    }

    public void SetWork(bool state)
    {
        if (state)
            Console.WriteLine("<-the designer is released from work");
        else
            Console.WriteLine("<-the designer is busy");
    }
}

class Director : Employee
{
    private string _text;

    public Director(IMediator mediator = null) : base(mediator) {}

    public void GiveCommand(string text)
    {
        _text = text;
        if (_text == "")
            Console.WriteLine("->the director knows that the designer is already working");
        else
            Console.WriteLine("->the director gave the command:" + _text);
        Mediator.Notify(this, _text);
    }
}

class Controller : IMediator
{
    private Designer _designer;
    private Director _director;

    public Controller(Designer designer, Director director)
    {
        _designer = designer;
        _director = director;
        designer.SetMediator(this);
        director.SetMediator(this);
    }

    public void Notify(Employee employee, string msg)
    {
        if (employee is Director)
        {
            if (msg == "")
                _designer.SetWork(false);
            else
                _designer.SetWork(true);
        }
        else if (employee is Designer)
        {
            if (msg == "the designer designs...")
                _director.GiveCommand("");
        }
    }
}

class Program
{
    static void Main()
    {
        Designer designer = new Designer();
        Director director = new Director();

        Controller mediator = new Controller(designer, director);
        
        director.GiveCommand("design");
        
        Console.WriteLine();
        
        designer.ExecuteWork();
    }
}