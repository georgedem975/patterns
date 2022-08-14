interface ISite
{
    string GetPage(int num);
}

class Site : ISite
{
    public string GetPage(int num) => "page " + num;
}

class SiteProxy : ISite
{
    private ISite _site;
    private Dictionary<int, string> _cache;

    public SiteProxy(ISite site)
    {
        _site = site;
        _cache = new Dictionary<int, string>();
    }

    public string GetPage(int num)
    {
        string page;
        if (_cache.ContainsKey(num))
        {
            page = _cache[num];
            page = "from cache " + page;
        }
        else
        {
            page = _site.GetPage(num);
            _cache.Add(num, page);
        }

        return page;
    }
}

class Program
{
    static void Main()
    {
        ISite mySite = new SiteProxy(new Site());
        
        Console.WriteLine(mySite.GetPage(1));
        Console.WriteLine(mySite.GetPage(2));
        Console.WriteLine(mySite.GetPage(3));
        
        Console.WriteLine(mySite.GetPage(2));
    }
}