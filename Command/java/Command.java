import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

interface ICommand{
    void positive();
    void negative();
}

class Conveyor{
    public void on(){
        System.out.println("the pipeline is running");
    }

    public void off(){
        System.out.println("the conveyor is stopped");
    }

    public void speedIncrease(){
        System.out.println("increased conveyor speed");
    }
    
    public void speedDecrease(){
        System.out.println("reduced conveyor speed");
    }
}

class ConveyorWorkCommand implements ICommand{
    private Conveyor conveyor;

    public ConveyorWorkCommand(Conveyor conveyor){
        this.conveyor = conveyor;
    }

    @Override
    public void positive(){
        conveyor.on();
    }

    @Override
    public void negative(){
        conveyor.off();
    }
}

class ConveyorAdjustCommand implements ICommand{
    private Conveyor conveyor;

    public ConveyorAdjustCommand(Conveyor conveyor){
        this.conveyor = conveyor;
    }

    @Override
    public void positive(){
        conveyor.speedIncrease();
    }

    @Override
    public void negative(){
        conveyor.speedDecrease();
    }
}

class MultiPult{
    private List<ICommand> commands;
    private Stack<ICommand> history;

    public MultiPult(){
        commands = new ArrayList<>();
        commands.add(null);
        commands.add(null);
        history = new Stack<>();
    }

    public void setCommand(int button, ICommand command){
        commands.set(button, command);
    }

    public void pressON(int button){
        commands.get(button).positive();
        history.push(commands.get(button));
    }

    public void pressCancel(){
        if (!history.empty()){
            history.pop().negative();
        }
    }
}

public class Main {
    public static void main(String[] args){

        Conveyor conveyor = new Conveyor();

        MultiPult multiPult = new MultiPult();
        multiPult.setCommand(0, new ConveyorWorkCommand(conveyor));
        multiPult.setCommand(1, new ConveyorAdjustCommand(conveyor));

        multiPult.pressON(0);
        multiPult.pressON(1);
        multiPult.pressCancel();
        multiPult.pressCancel();
    }
}