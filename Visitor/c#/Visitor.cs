interface IVisitor
{
    void Visit(Zoo zoo);
    
    void Visit(Cinema cinema);
    
    void Visit(Circus circus);
}

interface IPlace
{
    void Accept(IVisitor v);
}

class Zoo : IPlace
{
    public void Accept(IVisitor v) => v.Visit(this);
}

class Cinema : IPlace
{
    public void Accept(IVisitor v) => v.Visit(this);
}

class Circus : IPlace
{
    public void Accept(IVisitor v) => v.Visit(this);
}

class HolidayMaker : IVisitor
{
    public string Value;

    public void Visit(Zoo zoo) => Value = "zoo";
    
    public void Visit(Cinema cinema) => Value = "cinema";
    
    public void Visit(Circus circus) => Value = "circus";
}

class Program
{
    static void Main()
    {
        List<IPlace> places = new List<IPlace>() {new Zoo(), new Cinema(), new Circus()};

        foreach (IPlace place in places)
        {
            HolidayMaker visitor = new HolidayMaker();
            place.Accept(visitor);
            Console.WriteLine(visitor.Value);
        }
    }
}