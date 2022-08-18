class Phone
{
    private string _data;
    
    public Phone() => _data = "";
    
    public string AboutPhone() => _data;
    
    public void AppendData(string str) => _data += str;
}

interface IDeveloper
{
    void CreateDisplay();
    
    void CreateBox();
    
    void SystemInstall();
    
    Phone GetPhone();
}

class AndroidDeveloper : IDeveloper
{
    private Phone _phone;
    
    public AndroidDeveloper() => _phone = new Phone();
    
    public void CreateDisplay() => _phone.AppendData("(create) display Samsung; ");
    
    public void CreateBox() => _phone.AppendData("(create) corpus Samsung; ");
    
    public void SystemInstall() => _phone.AppendData("(install) system Android; ");
    
    public Phone GetPhone() => _phone;
}

class IphoneDeveloper : IDeveloper
{
    private Phone _phone;
    
    public IphoneDeveloper() => _phone = new Phone();
    
    public void CreateDisplay() => _phone.AppendData("(create) display Iphone; ");
    
    public void CreateBox() => _phone.AppendData("(create) corpus Iphone; ");
    
    public void SystemInstall() => _phone.AppendData("(install) system IOS; ");
    
    public Phone GetPhone() => _phone;
}

class Director
{
    private IDeveloper _developer;
    
    public Director(IDeveloper developer) => _developer = developer;
    
    public void SetDeveloper(IDeveloper developer) => _developer = developer;

    public Phone MountOnlyPhone()
    {
        _developer.CreateBox();
        _developer.CreateDisplay();
        return _developer.GetPhone();
    }

    public Phone MountFullPhone()
    {
        _developer.CreateBox();
        _developer.CreateDisplay();
        _developer.SystemInstall();
        return _developer.GetPhone();
    }
}

class Program
{
    static void Main()
    {
        IDeveloper androidDeveloper = new AndroidDeveloper();

        Director director = new Director(androidDeveloper);

        Phone samsung = director.MountFullPhone();
        Console.WriteLine(samsung.AboutPhone());

        IDeveloper iphoneDeveloper = new IphoneDeveloper();
        director.SetDeveloper(iphoneDeveloper);

        Phone iphone = director.MountOnlyPhone();
        Console.WriteLine(iphone.AboutPhone());
    }
}