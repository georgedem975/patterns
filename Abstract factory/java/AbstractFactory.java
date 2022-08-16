interface IEngine{
    void releaseEngine();
}

class JapaneseEngine implements IEngine{
    @Override
    public void releaseEngine(){
        System.out.println("japanese engine");
    }
}

class RussianEngine implements IEngine{
    @Override
    public void releaseEngine(){
        System.out.println("russian engine");
    }
}

interface ICar{
    void releaseCar(IEngine engine);
}

class JapaneseCar implements ICar{
    @Override
    public void releaseCar(IEngine engine){
        System.out.print("assembled a Japanese car: ");
        engine.releaseEngine();
    }
}

class RussianCar implements ICar{
    @Override
    public void releaseCar(IEngine engine){
        System.out.print("assembled a Russian car: ");
        engine.releaseEngine();
    }
}

interface IFactory{
    IEngine createEngine();
    ICar createCar();
}

class JapaneseFactory implements IFactory{
    @Override
    public IEngine createEngine(){
        return new JapaneseEngine();
    }

    @Override
    public ICar createCar(){
        return new JapaneseCar();
    }
}

class RussianFactory implements IFactory{
    @Override
    public IEngine createEngine(){
        return new RussianEngine();
    }

    @Override
    public ICar createCar(){
        return new RussianCar();
    }
}

public class Main{
    public static void main(String[] args){
        IFactory jFactory = new JapaneseFactory();

        IEngine jEngine = jFactory.createEngine();
        ICar jCar = jFactory.createCar();

        jCar.releaseCar(jEngine);

        IFactory rFactory = new RussianFactory();

        IEngine rEngine = rFactory.createEngine();
        ICar rCar = rFactory.createCar();
        
        rCar.releaseCar(rEngine);
    }
}