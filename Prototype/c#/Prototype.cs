interface IAnimal
{
    void SetName(string name);
    
    string GetName();
    
    IAnimal Clone();
}

class Sheep : IAnimal
{
    private string _name;
    
    public Sheep() {}
    
    private Sheep(Sheep donor) => this._name = donor._name;
    
    public void SetName(string name) => this._name = name;
    
    public string GetName() => _name;
    
    public IAnimal Clone() => new Sheep(this);
}

class Program
{
    static void Main()
    {
        IAnimal sheepDonor = new Sheep();
        sheepDonor.SetName("sheep");

        IAnimal sheepClone = sheepDonor.Clone();
        
        Console.WriteLine(sheepDonor.GetName());
        Console.WriteLine(sheepClone.GetName());
    }
}