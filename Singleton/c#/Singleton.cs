public class DatabaseHelper
{
    private string _data;
    
    private static DatabaseHelper _databseConnection;
    
    private DatabaseHelper() => Console.WriteLine("connecting to the database");

    public static DatabaseHelper GetConnection()
    {
        if (_databseConnection == null)
            _databseConnection = new DatabaseHelper();
        return _databseConnection;
    }

    public string SelectData() => _data;

    public void InsertData(string d)
    {
        Console.WriteLine("new data: " + d + "(entered into the database)");
        _data = d;
    }
}

class Program
{
    static void Main()
    {
        DatabaseHelper.GetConnection().InsertData("123");
        Console.WriteLine("Data: " + DatabaseHelper.GetConnection().SelectData());
    }
}