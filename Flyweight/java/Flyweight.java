import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;

class Shared{
    private String company;
    
    private String position;
    
    public Shared(String company, String position){
        this.company = company;
        this.position = position;
    }
    
    public String getCompany(){
        return company;
    }
    
    public String getPosition(){
        return position;
    }
}

class Unigue{
    private String name;
    
    private String passport;
    
    public Unigue(String name, String passport){
        this.name = name;
        this.passport = passport;
    }
    
    public String getName(){
        return name;
    }
    
    public String getPassport(){
        return passport;
    }
}

class Flyweight{
    private Shared shared;

    public Flyweight(Shared shared){
        this.shared = shared;
    }

    public void process(Unigue unique){
        System.out.println("New data: shared - " + shared.getCompany() + "_" + shared.getPosition()
                + " unique - " + unique.getName() + "_" + unique.getPassport());
    }

    public String getData(){
        return shared.getCompany() + "_" + shared.getPosition();
    }
}

class FlyweightFactory{
    private Hashtable flyweights;

    private String getKey(Shared shared){
        return shared.getCompany() + "_" + shared.getPosition();
    }

    public FlyweightFactory(List<Shared> shareds){
        flyweights = new Hashtable();
        for (Shared shared : shareds)
            flyweights.put(getKey(shared), new Flyweight(shared));
    }

    public Flyweight getFlyweight(Shared shared){
        String key = getKey(shared);
        if (!flyweights.containsKey(key)){
            System.out.println("Flyweight factory: object not found " + key);
            flyweights.put(key, new Flyweight(shared));
        }
        else {
            System.out.println("Flyweight factory: object found " + key);
        }
        return (Flyweight) flyweights.get(key);
    }

    public void listFlyweights(){
        int count = flyweights.size();
        System.out.println("Flyweight factory: count = " + count);
        for (Object pair : flyweights.values()){
            System.out.println(((Flyweight)pair).getData());
        }
    }
}

public class Main {
    static void addSpecialistDatabase(FlyweightFactory flyweightFactory, String company, String position,
                                       String name, String passport){
        System.out.println();
        Flyweight flyweight = flyweightFactory.getFlyweight(new Shared(company, position));
        flyweight.process(new Unigue(name, passport));
    }

    public static void main(String[] args){
        List<Shared> shareds = new ArrayList<>();
        shareds.add(new Shared("Microsoft", "manager"));
        shareds.add(new Shared("Google", "manager"));
        shareds.add(new Shared("Google", "developer"));
        shareds.add(new Shared("Apple", "developer"));

        FlyweightFactory flyweightFactory = new FlyweightFactory(shareds);

        flyweightFactory.listFlyweights();

        addSpecialistDatabase(flyweightFactory,
                "Google",
                "developer",
                "George",
                "12345");

        addSpecialistDatabase(flyweightFactory,
                "Apple",
                "manager",
                "Mark",
                "67890");

        flyweightFactory.listFlyweights();
    }
}