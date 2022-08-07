interface IExpression
{
    public void Interpret();
}

class TerminalExpression : IExpression
{
    private string _statement;
    
    public TerminalExpression(string statement) => _statement = statement;

    public void Interpret()
    {
        Console.WriteLine(this._statement + " TerminalExpression");
    }
}

class NonTerminalExpression : IExpression
{
    private IExpression _expression;
    private int _times;

    public NonTerminalExpression(IExpression expression, int times)
    {
        _expression = expression;
        _times = times;
    }

    public void Interpret()
    {
        for (int i = 0; i < _times; i++)
        {
            this._expression.Interpret();
        }
    }
}

class Program
{
    static void Main()
    {
        IExpression terminalExpression = new TerminalExpression("hello");
        IExpression nonTerminalExpression = new NonTerminalExpression(terminalExpression, 2);
        
        nonTerminalExpression.Interpret();
    }
}