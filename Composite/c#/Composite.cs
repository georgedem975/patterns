abstract class Item
{
    protected string ItemName;
    
    protected string OwnerName;
    
    public void SetOwner(string o) => OwnerName = o;
    
    public Item(string name) => ItemName = name;
    
    public virtual void Add(Item subItem) {}
    
    public virtual void Remove(Item subItem) {}
    
    public abstract void Display();
}

class ClickableItem : Item
{
    public ClickableItem(string name) : base(name) {}

    public override void Add(Item subItem)
    {
        throw new Exception();
    }

    public override void Remove(Item subItem)
    {
        throw new Exception();
    }

    public override void Display()
    {
        Console.WriteLine(ItemName);
    }
}

class DropDownItem : Item
{
    private List<Item> _children;

    public DropDownItem(string name) : base(name)
    {
        _children = new List<Item>();
    }

    public override void Add(Item subItem)
    {
        subItem.SetOwner(this.ItemName);
        _children.Add(subItem);
    }

    public override void Remove(Item subItem) => _children.Remove(subItem);

    public override void Display()
    {
        foreach (Item item in _children)
        {
            if (OwnerName != null)
                Console.Write(OwnerName + ItemName);
            item.Display();
        }
    }
}

class Program
{
    static void Main()
    {
        Item file = new DropDownItem("file->");

        Item create = new DropDownItem("create->");
        Item open = new DropDownItem("open->");
        Item exit = new ClickableItem("exit");
        
        file.Add(create);
        file.Add(open);
        file.Add(exit);

        Item project = new ClickableItem("project...");
        Item repository = new ClickableItem("repository...");
        
        create.Add(project);
        create.Add(repository);

        Item solution = new ClickableItem("solution...");
        Item folder = new ClickableItem("folder...");
        
        open.Add(solution);
        open.Add(folder);
        
        file.Display();
        Console.WriteLine();
        
        file.Remove(create);
        
        file.Display();
    }
}