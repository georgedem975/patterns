interface IEngine
{
    void ReleaseEngine();
}

class JapaneseEngine : IEngine
{
    public void ReleaseEngine() => Console.WriteLine("japanese engine");
}

class RussianEngine : IEngine
{
    public void ReleaseEngine() => Console.WriteLine("russian engine");
}

interface ICar
{
    void ReleaseCar(IEngine engine);
}

class JapaneseCar : ICar
{
    public void ReleaseCar(IEngine engine)
    {
        Console.Write("assembled a Japanese car: ");
        engine.ReleaseEngine();
    }
}

class RussianCar : ICar
{
    public void ReleaseCar(IEngine engine)
    {
        Console.Write("assembled a Russian car: ");
        engine.ReleaseEngine();
    }
}

interface IFactory
{
    IEngine CreateEngine();
    ICar CreateCar();
}

class JapaneseFactory : IFactory
{
    public ICar CreateCar() => new JapaneseCar();
    
    public IEngine CreateEngine() => new JapaneseEngine();
}

class RussianFactory : IFactory
{
    public ICar CreateCar() => new RussianCar();
    
    public IEngine CreateEngine() => new RussianEngine();
}

class Program
{
    static void Main()
    {
        IFactory jFactory = new JapaneseFactory();

        IEngine jEngine = jFactory.CreateEngine();
        ICar jCar = jFactory.CreateCar();
        
        jCar.ReleaseCar(jEngine);

        IFactory rFactory = new RussianFactory();

        IEngine rEngine = rFactory.CreateEngine();
        ICar rCar = rFactory.CreateCar();
        
        rCar.ReleaseCar(rEngine);
    }
}