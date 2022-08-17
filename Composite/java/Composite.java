import java.util.ArrayList;
import java.util.List;

abstract class Item{
    protected String itemName; 
    protected String ownerName;
    
    public Item(String name){
        itemName = name;
    }
    
    public void setOwner(String o){
        ownerName = o;
    }
    
    public abstract void add(Item subItem) throws Exception;
    
    public abstract void remove(Item subItem) throws Exception;
    
    public abstract void display();
}

class ClickableItem extends Item{
    public ClickableItem(String name){
        super(name);
    }
    
    @Override
    public void add(Item subItem) throws Exception{
        throw new Exception();
    }
    
    @Override
    public void remove(Item subItem) throws Exception{
        throw new Exception();
    }
    
    @Override
    public void display(){
        System.out.println(itemName);
    }
}

class DropDownItem extends Item{
    private List<Item> children;
    
    public DropDownItem(String name){
        super(name);
        children = new ArrayList<>();
    }
    
    @Override
    public void add(Item subItem) throws Exception{
        subItem.setOwner(this.itemName);
        children.add(subItem);
    }
    
    @Override
    public void remove(Item subItem) throws Exception{
        children.remove(subItem);
    }
    
    @Override
    public void display(){
        for (Item child : children){
            if (ownerName != null)
                System.out.print(ownerName + itemName);
            child.display();
        }
    }
}

public class Main {
    public static void main(String[] args) throws Exception{
        Item file = new DropDownItem("file->");

        Item create = new DropDownItem("create->");
        Item open = new DropDownItem("open->");
        Item exit = new ClickableItem("exit");

        file.add(create);
        file.add(open);
        file.add(exit);

        Item project = new ClickableItem("project...");
        Item repository = new ClickableItem("repository...");

        create.add(project);
        create.add(repository);

        Item solution = new ClickableItem("solution...");
        Item folder = new ClickableItem("folder...");

        open.add(solution);
        open.add(folder);

        file.display();
        System.out.println();

        file.remove(create);

        file.display();
    }
}