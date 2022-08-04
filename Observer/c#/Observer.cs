interface IObserver
{
    void Update(double p);
}

interface IObservable
{
    void AddObserver(IObserver o);
    void RemoveObserver(IObserver o);
    void Notify();
}

class Product : IObservable
{
    private List<IObserver> _observers;
    private double _price;
    
    public Product(double p)
    {
        _price = p;
        _observers = new List<IObserver>();
    }

    public void ChangePrice(double p)
    {
        _price = p;
        Notify();
    }

    public void AddObserver(IObserver o)
    {
        _observers.Add(o);
    }

    public void RemoveObserver(IObserver o)
    {
        _observers.Remove(o);
    }

    public void Notify()
    {
        foreach (IObserver o in _observers.ToList())
        {
            o.Update(_price);
        }
    }
}

class Wholesale : IObserver
{
    private IObservable product;

    public Wholesale(IObservable obj)
    {
        product = obj;
        obj.AddObserver(this);
    }

    public void Update(double p)
    {
        if (p < 300)
        {
            Console.WriteLine("the wholesaler bought the goods at a price " + p);
            product.RemoveObserver(this);
        }
    }
}

class Buyer : IObserver
{
    private IObservable product;

    public Buyer(IObservable obj)
    {
        product = obj;
        obj.AddObserver(this);
    }

    public void Update(double p)
    {
        if (p < 350)
        {
            Console.WriteLine("the buyer purchased the product at the price " + p);
            product.RemoveObserver(this);
        }
    }
}

class Program
{
    static void Main()
    {
        Product product = new Product(400);

        Wholesale wholesale = new Wholesale(product);
        Buyer buyer = new Buyer(product);
        
        product.ChangePrice(320);
        product.ChangePrice(280);
    }
}