using System.Collections;

struct Shared
{
    private string _company;
    
    private string _position;

    public Shared(string company, string position)
    {
        _company = company;
        _position = position;
    }
    
    public string Company { get => _company; }

    public string Position { get => _position; }
}

struct Unique
{
    private string _name;
    
    private string _passport;

    public Unique(string name, string passport)
    {
        _name = name;
        _passport = passport;
    }
    
    public string Name { get => _name; }
    
    public string Passport { get => _passport; }
}

class Flyweight
{
    private Shared _shared;
    
    public Flyweight(Shared shared) => _shared = shared;

    public void Process(Unique unique)
    {
        Console.WriteLine("New data: shared - " + _shared.Company + "_" + _shared.Position + " unique - " + unique.Name + "_" + unique.Passport);
    }

    public string GetData() => _shared.Company + "_" + _shared.Position;
}

class FlyweightFactory
{
    private Hashtable _flyweights;
    
    private string GetKey(Shared shared) => shared.Company + "_" + shared.Position;

    public FlyweightFactory(List<Shared> shareds)
    {
        _flyweights = new Hashtable();
        foreach (Shared shared in shareds)
        {
            _flyweights.Add(GetKey(shared), new Flyweight(shared));
        }
    }

    public Flyweight GetFlyweight(Shared shared)
    {
        string key = GetKey(shared);
        if (!_flyweights.Contains(key))
        {
            Console.WriteLine("Flyweight factory: object not found " + key);
            _flyweights.Add(key, new Flyweight(shared));
        }
        else
        {
            Console.WriteLine("Flyweight factory: object found " + key);
        }

        return (Flyweight) _flyweights[key];
    }

    public void ListFlyweights()
    {
        int count = _flyweights.Count;
        Console.WriteLine("Flyweight factory: count = " + count);
        foreach (Flyweight pair in _flyweights.Values)
        {
            Console.WriteLine(pair.GetData());
        }
    }
}

class Program
{
    static void AddSpecialistDatabase(FlyweightFactory flyweightFactory,
        string company, string position, string name, string passport)
    {
        Console.WriteLine();
        Flyweight flyweight = flyweightFactory.GetFlyweight(new Shared(company, position));
        flyweight.Process(new Unique(name, passport));
    }

    static void Main()
    {
        FlyweightFactory flyweightFactory = new FlyweightFactory(new List<Shared>()
        {
            new Shared("Microsoft", "manager"),
            new Shared("Google", "manager"),
            new Shared("Google", "developer"),
            new Shared("Apple", "developer"),
        });
        
        flyweightFactory.ListFlyweights();
        
        AddSpecialistDatabase(flyweightFactory,
            "Google",
            "developer",
            "George",
            "12345");
        
        AddSpecialistDatabase(flyweightFactory,
            "Apple",
            "manager",
            "Mark",
            "67890");
        
        flyweightFactory.ListFlyweights();
    }
}