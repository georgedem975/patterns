interface IScales
{
    float GetWeight();
}

class RussianScales  IScales
{
    private float _currentWeight;

    public RussianScales(float cw) = _currentWeight = cw;

    public float GetWeight() = _currentWeight;
}

class BritishScales
{
    private float _currentWeight;

    public BritishScales(float cw) = _currentWeight = cw;

    public float GetWeight() = _currentWeight;
}

class AdapterForBritishScales  IScales
{
    private BritishScales _britishScales;

    public AdapterForBritishScales(BritishScales britishScales) = this._britishScales = britishScales;

    public float GetWeight() = _britishScales.GetWeight()  0.453f;
}

class Program
{
    static void Main()
    {
        float kg = 55.0f;
        float lb = 55.0f;

        IScales rScales = new RussianScales(kg);
        IScales bScales = new AdapterForBritishScales(new BritishScales(lb));
        
        Console.WriteLine(rScales.GetWeight());
        Console.WriteLine(bScales.GetWeight());
    }
}