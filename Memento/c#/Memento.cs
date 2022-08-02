interface IMemento
{
    int GetDollars();
    int GetEuro();
}

class ExchangeMemento : IMemento
{
    private int dollars;
    private int euro;

    public ExchangeMemento(int d, int e)
    {
        dollars = d;
        euro = e;
    }

    public int GetDollars() => dollars;

    public int GetEuro() => euro;
}

class Exchange
{
    private int _dollars;
    private int _euro;

    public Exchange(int d, int e)
    {
        _dollars = d;
        _euro = e;
    }

    public void GetDollars() => Console.WriteLine("dollars: " + _dollars);

    public void GetEuro() => Console.WriteLine("Euro: " + _euro);

    public void Sell()
    {
        if (_dollars > 0) --_dollars;
    }

    public void Buy() => ++_euro;

    public ExchangeMemento Save() => new ExchangeMemento(_dollars, _euro);

    public void Restore(IMemento exchangeMemento)
    {
        _dollars = exchangeMemento.GetDollars();
        _euro = exchangeMemento.GetEuro();
    }
}

class Memory
{
    private Stack<IMemento> history;
    private Exchange exchange;

    public Memory(Exchange exchange)
    {
        this.exchange = exchange;
        history = new Stack<IMemento>();
    }

    public void Backup() => history.Push(exchange.Save());

    public void Undo()
    {
        if (history.Count == 0) return;
        exchange.Restore(history.Pop());
    }
}

class Program
{
    static void Main()
    {
        Exchange exchange = new Exchange(10, 10);

        Memory memory = new Memory(exchange);
        
        exchange.GetDollars();
        exchange.GetEuro();
        
        Console.WriteLine("Sell Dollars, Buy Euro");
        exchange.Sell();
        exchange.Buy();
        
        exchange.GetDollars();
        exchange.GetEuro();
        
        Console.WriteLine("Save");
        memory.Backup();
        
        Console.WriteLine("Sell Dollars, Buy Euro");
        exchange.Sell();
        exchange.Buy();
        
        exchange.GetDollars();
        exchange.GetEuro();
        
        Console.WriteLine("Restoring the state");
        memory.Undo();
        
        exchange.GetDollars();
        exchange.GetEuro();
    }
}