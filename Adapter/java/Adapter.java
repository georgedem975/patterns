interface IScales{
    float getWeight();
}

class RussianScales implements IScales{
    private float currentWeight;

    public RussianScales(float cw){
        this.currentWeight = cw;
    }

    @Override
    public float getWeight(){
        return currentWeight;
    }
}

class BritishScales{
    float currentWeight;

    public BritishScales(float cw){
        this.currentWeight = cw;
    }

    public float getWeight(){
        return currentWeight;
    }
}

class AdapterBritishScales implements IScales{
    BritishScales britishScales;

    public AdapterBritishScales(BritishScales britishScales){
        this.britishScales = britishScales;
    }

    @Override
    public float getWeight(){
        return britishScales.getWeight() * 0.453f;
    }
}

public class Main{
    public static void main(String[] args){
        float kg = 55.0f;
        float lb = 55.0f;

        IScales rScales = new RussianScales(kg);
        IScales bScales = new AdapterBritishScales(new BritishScales(lb));

        System.out.println(rScales.getWeight());
        System.out.println(bScales.getWeight());
    }
}