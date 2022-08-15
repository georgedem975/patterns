interface IDataReader
{
    void Read();
}

class DataBaseReader : IDataReader
{
    public void Read() => Console.Write("data from the database ");
}

class FileReader : IDataReader
{
    public void Read() => Console.Write("data from the file ");
}

abstract class Sender
{
    protected IDataReader _reader;

    public Sender(IDataReader dataReader) => _reader = dataReader;
    
    public void SetDataReader(IDataReader dataReader) => _reader = dataReader;
    
    public abstract void Send();
}

class EmailSender : Sender
{
    public EmailSender(IDataReader dataReader) : base(dataReader) {}

    public override void Send()
    {
        _reader.Read();
        Console.WriteLine("sent by email");
    }
}

class TelegramBotSender : Sender
{
    public TelegramBotSender(IDataReader dataReader) : base(dataReader) {}

    public override void Send()
    {
        _reader.Read();
        Console.WriteLine("sent by telegram bot");
    }
}

class Program
{
    static void Main()
    {
        Sender sender = new EmailSender(new DataBaseReader());
        sender.Send();
        
        sender.SetDataReader(new FileReader());
        sender.Send();

        sender = new TelegramBotSender(new DataBaseReader());
        sender.Send();
    }
}