interface IReader
{
    void Parse(string url);
}

class ResourceReader
{
    private IReader _reader;

    public ResourceReader(IReader reader) => this._reader = reader;

    public void SetStrategy(IReader reader) => this._reader = reader;
    
    public void Read(string url) => _reader.Parse(url);
}

class NewsSiteReader : IReader
{
    public void Parse(string url) => Console.WriteLine("parse site " + url);
}

class SocialNetworkReader : IReader
{
    public void Parse(string url) => Console.WriteLine("parse social networks " + url);
}

class TelegramChannelReader : IReader
{
    public void Parse(string url) => Console.WriteLine("parse telegram channel " + url);
}

class Program
{
    static void Main()
    {
        ResourceReader resourceReader = new ResourceReader(new NewsSiteReader());

        string url = "news site";
        resourceReader.Read(url);

        url = "social network";
        resourceReader.SetStrategy(new SocialNetworkReader());
        resourceReader.Read(url);

        url = "telegram channel";
        resourceReader.SetStrategy(new TelegramChannelReader());
        resourceReader.Read(url);
    }
}