interface IProcessor
{
    void Process();
}

class Transmitter : IProcessor
{
    private string _data;
    
    public Transmitter(string data) => this._data = data;
    
    public void Process() => Console.WriteLine("Data " + _data + " transmitted via the communication channel");
}

abstract class Shell : IProcessor
{
    protected IProcessor Processor;
    
    public Shell(IProcessor processor) => Processor = processor;
    
    public virtual void Process() => Processor.Process();
}

class HammingCoder : Shell
{
    public HammingCoder(IProcessor processor) : base(processor) {}

    public override void Process()
    {
        Console.Write("noise-resistant Hamming code has been applied->");
        Processor.Process();
    }
}

class Encryptor : Shell
{
    public Encryptor(IProcessor processor) : base(processor) {}

    public override void Process()
    {
        Console.Write("data encryption->");
        Processor.Process();
    }
}

class Program
{
    static void Main()
    {
        IProcessor transmitter = new Transmitter("12345");
        transmitter.Process();
        Console.WriteLine();

        Shell hammingCoder = new HammingCoder(transmitter);
        hammingCoder.Process();
        Console.WriteLine();

        Shell encoder = new Encryptor(hammingCoder);
        encoder.Process();
    }
}