class ProviderCommunication
{
    public void Receive() => Console.WriteLine("receiving products from the manufacturer");

    public void Payment() => Console.WriteLine("payment");
}

class Site
{
    public void Placement() => Console.WriteLine("placement on the website");

    public void Del() => Console.WriteLine("removal from the site");
}

class Database
{
    public void Insert() => Console.WriteLine("writing to the database");

    public void Del() => Console.WriteLine("deleting from the database");
}

class MarketPlace
{
    private ProviderCommunication _providerCommunication;

    private Site _site;
    
    private Database _database;

    public MarketPlace()
    {
        _providerCommunication = new ProviderCommunication();
        _site = new Site();
        _database = new Database();
    }

    public void ProductReceipt()
    {
        _providerCommunication.Receive();
        _site.Placement();
        _database.Insert();
    }

    public void ProductRelease()
    {
        _providerCommunication.Payment();
        _site.Del();
        _database.Del();
    }
}

class Program
{
    static void Main()
    {
        MarketPlace marketPlace = new MarketPlace();
        
        marketPlace.ProductReceipt();
        
        Console.WriteLine();
        
        marketPlace.ProductRelease();
    }
}