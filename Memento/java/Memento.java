import java.util.Stack;

interface IMemento{
    int getDollars();
    int getEuro();
}

class ExchangeMemento implements IMemento{
    private int dollars;
    private int euro;

    public ExchangeMemento(int d, int e){
        dollars = d;
        euro = e;
    }

    @Override
    public int getDollars() {
        return dollars;
    }

    @Override
    public  int getEuro() {
        return euro;
    }
}

class Exchange{
    private int dollars;
    private int euro;

    public Exchange(int d, int e){
        dollars = d;
        euro = e;
    }

    public void getDollars(){
        System.out.println("Dollars: " + dollars);
    }

    public void getEuro(){
        System.out.println("Euro: " + euro);
    }

    public void sell(){
        if (dollars > 0) --dollars;
    }

    public void buy(){
        ++euro;
    }

    public ExchangeMemento save(){
        return new ExchangeMemento(dollars, euro);
    }

    public void restore(IMemento exchangeMemento){
        dollars = exchangeMemento.getDollars();
        euro = exchangeMemento.getEuro();
    }
}

class Memory{
    private Stack<IMemento> history;
    Exchange exchange;

    public Memory(Exchange exchange){
        this.exchange = exchange;
        history = new Stack<>();
    }

    public void backup(){
        history.push(exchange.save());
    }

    public void undo(){
        if (history.isEmpty()) return;
        exchange.restore(history.pop());
    }
}

public class Main {
    public static void main(String[] args) {
        Exchange exchange = new Exchange(10, 10);

        Memory memory = new Memory(exchange);

        exchange.getDollars();
        exchange.getEuro();

        System.out.println("Sell dollars, buy euro");
        exchange.sell();
        exchange.buy();

        exchange.getDollars();
        exchange.getEuro();

        System.out.println("Saving state");
        memory.backup();

        System.out.println("Sell dollars, buy euro");
        exchange.sell();
        exchange.buy();

        exchange.getDollars();
        exchange.getEuro();

        System.out.println("Restoring the state");
        memory.undo();

        exchange.getDollars();
        exchange.getEuro();
    }
}