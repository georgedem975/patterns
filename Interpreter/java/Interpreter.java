interface IExpression{
    public void interpret();
}

class TerminalExpression implements IExpression{
    private String statement;

    public TerminalExpression(final String statement){
        this.statement = statement;
    }

    @Override
    public void interpret(){
        System.out.println(this.statement + " TerminalExpression");
    }
}

class NonTerminalExpression implements IExpression{
    private IExpression expression = null;
    private int times;

    public NonTerminalExpression(IExpression expression, int times){
        this.expression = expression;
        this.times = times;
    }
    
    @Override
    public void interpret(){
        for (int i = 0; i < this.times; i++){
            this.expression.interpret();
        }
    }
}

public class Main {
    public static void main(String[] args){
        IExpression terminalExpression = new TerminalExpression("hello");
        IExpression nonTerminalExpression = new NonTerminalExpression(terminalExpression, 2);

        nonTerminalExpression.interpret();
    }
}