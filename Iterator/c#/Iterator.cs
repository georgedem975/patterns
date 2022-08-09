internal class DataStack
{
    private int[] _items = new int[10];
    private int _length;

    public DataStack() => _length = -1;

    public DataStack(DataStack myStack)
    {
        this._items = myStack._items;
        this._length = myStack._length;
    }
    
    public int[] Items { get => _items; }

    public int Length { get => _length; }

    public void Push(int value) => _items[++_length] = value;
    
    public int Pop() => _items[_length--];

    public static bool operator ==(DataStack myStack1, DataStack myStack2)
    {
        StackIterator it1 = new StackIterator(myStack1),
            it2 = new StackIterator(myStack2);

        while (it1.IsEnd() || it2.IsEnd())
        {
            if (it1.Get() != it2.Get()) break;
            it1++;
            it2++;
        }

        return !it1.IsEnd() && !it2.IsEnd();
    }

    public static bool operator !=(DataStack myStack1, DataStack myStack2)
    {
        return !(myStack1 == myStack2);
    }
}

class StackIterator
{
    private DataStack _stack;
    private int _index;

    public StackIterator(DataStack myStack)
    {
        this._stack = myStack;
        this._index = 0;
    }

    public static StackIterator operator ++(StackIterator s)
    {
        s._index++;
        return s;
    }

    public int Get()
    {
        if (_index < _stack.Length)
        {
            return _stack.Items[_index];
        }

        return 0;
    }

    public bool IsEnd() => _index != _stack.Length + 1;
}

class Program
{
    static void Main()
    {
        DataStack myStack1 = new DataStack();
        
        for (int i =0; i < 5; i++)
            myStack1.Push(i);

        DataStack myStack2 = new DataStack(myStack1);
        
        Console.WriteLine(myStack1 == myStack2);
        
        myStack2.Push(10);
        
        Console.WriteLine(myStack1 == myStack2);
    }
}