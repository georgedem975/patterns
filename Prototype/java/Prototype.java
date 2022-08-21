interface IAnimal{
    void setName(String name);
    
    String getName();
    
    IAnimal clone();
}

class Sheep implements IAnimal{
    private String name;
    
    public Sheep(){}
    
    private Sheep(Sheep donor){
        this.name = donor.name;
    }
    
    @Override
    public void setName(String name){
        this.name = name;
    }
    
    @Override
    public String getName(){
        return name;
    }
    
    @Override
    public IAnimal clone(){
        return new Sheep(this);
    }
}

public class Main {
    public static void main(String[] args){
        IAnimal sheepDonor = new Sheep();
        sheepDonor.setName("sheep");

        IAnimal sheepClone = sheepDonor.clone();

        System.out.println(sheepDonor.getName());
        System.out.println(sheepClone.getName());
    }
}