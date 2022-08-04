import java.util.ArrayList;
import java.util.List;

interface IObserver{
    void update(double p);
}

interface IObservable{
    void addObserver(IObserver o);
    void removeObserver(IObserver o);
    void updateNotify();
}

class Product implements IObservable{
    private List<IObserver> observers;
    private double price;

    public Product(double p){
        price = p;
        observers = new ArrayList<>();
    }

    public void changePrice(double p){
        price = p;
        updateNotify();
    }

    @Override
    public void addObserver(IObserver o){
        observers.add(o);
    }

    @Override
    public void removeObserver(IObserver o){
        observers.remove(o);
    }

    @Override
    public void updateNotify(){
        for (Object o : observers.toArray()){
            ((IObserver)o).update(price);
        }
    }
}

class Wholesale implements IObserver{
    private IObservable product;

    public Wholesale(IObservable obj){
        product = obj;
        obj.addObserver(this);
    }

    @Override
    public void update(double p){
        if (p < 300){
            System.out.println("the wholesaler bought the goods at a price " + p);
            product.removeObserver(this);
        }
    }
}

class Buyer implements IObserver{
    private IObservable product;

    public Buyer(IObservable obj){
        product = obj;
        obj.addObserver(this);
    }
    
    @Override
    public void update(double p){
        if (p < 350){
            System.out.println("the buyer purchased the product at the price " + p);
            product.removeObserver(this);
        }
    }
}

public class Main {
    public static void main(String[] args){

        Product product = new Product(400);

        Wholesale wholesale = new Wholesale(product);
        Buyer buyer = new Buyer(product);

        product.changePrice(320);
        product.changePrice(280);
    }
}