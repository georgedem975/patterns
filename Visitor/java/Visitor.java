import java.util.ArrayList;
import java.util.List;

interface IVisitor{
    void visit(Zoo zoo);
    
    void visit(Cinema cinema);
    
    void visit(Circus circus);
}

interface IPlace{
    void accept(IVisitor v);
}

class Zoo implements IPlace{
    @Override
    public void accept(IVisitor v){
        v.visit(this);
    }
}

class Cinema implements IPlace{
    @Override
    public void accept(IVisitor v){
        v.visit(this);
    }
}

class Circus implements IPlace{
    @Override
    public void accept(IVisitor v){
        v.visit(this);
    }
}

class HolidayMaker implements IVisitor {
    public String value;

    @Override
    public void visit(Zoo zoo) {
        value = "zoo";
    }

    @Override
    public void visit(Cinema cinema) {
        value = "cinema";
    }

    @Override
    public void visit(Circus circus) {
        value = "circus";
    }
}

public class Main{
    public static void main(String[] args){

        List<IPlace> places = new ArrayList<>();

        places.add(new Zoo());
        places.add(new Cinema());
        places.add(new Circus());

        for (IPlace place : places){
            HolidayMaker visitor = new HolidayMaker();
            place.accept(visitor);
            System.out.println(visitor.value);
        }
    }
}