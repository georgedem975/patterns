abstract class State
{
    protected TrafficLight _trafficLight;
    public TrafficLight TrafficLight { set => _trafficLight = value; }
    public abstract void NextState();
    public abstract void PreviousState();
}

class TrafficLight
{
    private State _state;
    
    public TrafficLight(State st) => SetState(st);

    public void SetState(State st)
    {
        _state = st;
        _state.TrafficLight = this;
    }

    public void NextState()
    {
        _state.NextState();
    }

    public void PreviousState()
    {
        _state.PreviousState();
    }
}

class GreenState : State
{
    public override void NextState()
    {
        Console.WriteLine("from green to yellow");
        _trafficLight.SetState(new YellowState());
    }

    public override void PreviousState()
    {
        Console.WriteLine("Green color");
    }
}

class YellowState : State
{
    public override void NextState()
    {
        Console.WriteLine("from yellow to red");
        _trafficLight.SetState(new RedState());
    }

    public override void PreviousState()
    {
        Console.WriteLine("from yellow to green");
        _trafficLight.SetState(new GreenState());
    }
}

class RedState : State
{
    public override void NextState()
    {
        Console.WriteLine("red color");
    }

    public override void PreviousState()
    {
        Console.WriteLine("from red to yellow");
        _trafficLight.SetState(new YellowState());
    }
}

class Program
{
    static void Main()
    {
        TrafficLight trafficLight = new TrafficLight(new GreenState());
        
        trafficLight.NextState();
        trafficLight.NextState();
        trafficLight.NextState();
        trafficLight.PreviousState();
        trafficLight.PreviousState();
        trafficLight.PreviousState();
    }
}