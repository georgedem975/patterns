class ProviderCommunication{
    public void receive(){
        System.out.println("receiving products from the manufacturer");
    }

    public void payment(){
        System.out.println("payment");
    }
}

class Site{
    public void placement(){
        System.out.println("placement on the website");
    }

    public void del(){
        System.out.println("removal from the site");
    }
}

class Database{
    public void insert(){
        System.out.println("writing to the database");
    }

    public void del(){
        System.out.println("deleting from the database");
    }
}

class MarketPlace{
    private ProviderCommunication providerCommunication;

    private Site site;

    private Database database;
    
    public MarketPlace(){
        providerCommunication = new ProviderCommunication();
        site = new Site();
        database = new Database();
    }

    public void productReceipt(){
        providerCommunication.receive();
        site.placement();
        database.insert();
    }

    public void productRelease(){
        providerCommunication.payment();
        site.del();
        database.del();
    }
}

public class Main{
    public static void main(String[] args){
        MarketPlace marketPlace = new MarketPlace();

        marketPlace.productReceipt();

        System.out.println();

        marketPlace.productRelease();
    }
}