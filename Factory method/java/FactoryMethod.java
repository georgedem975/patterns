interface IProduction{
    void release();
}

class Car implements IProduction{
    @Override
    public void release(){
        System.out.println("car");
    }
}

class Truck implements IProduction{
    @Override
    public void release(){
        System.out.println("truck");
    }
}

interface IWorkShop{
    IProduction create();
}

class CarWorkShop implements IWorkShop{
    @Override
    public IProduction create(){
        return new Car();
    }
}

class TruckWorkShop implements IWorkShop{
    @Override
    public IProduction create(){
        return new Truck();
    }
}

public class Main {
    public static void main(String[] args){
        IWorkShop creator = new CarWorkShop();

        IProduction car = creator.create();

        creator = new TruckWorkShop();

        IProduction truck = creator.create();

        car.release();
        truck.release();
    }
}