interface IWorker{
    
    IWorker setNextWorker(IWorker worker);
    String execute(String command);
}

abstract class AbsWorker implements IWorker{

    private IWorker nextWorker;

    public AbsWorker(){
        nextWorker = null;
    }

    @Override
    public IWorker setNextWorker(IWorker worker){
        nextWorker = worker;
        return worker;
    }

    @Override
    public String execute(String command){
        if (nextWorker != null)
            return nextWorker.execute(command);
        return "";
    }
}

class Designer extends AbsWorker{

    @Override
    public String execute(String command){
        if (command.equals("design a house")){
            return "the designer executed the command: " + command;
        }
        return super.execute(command);
    }
}

class Carpenters extends  AbsWorker{

    @Override
    public String execute(String command){
        if (command.equals("laying a brick")){
            return "the carpenter executed the command: " + command;
        }
        return super.execute(command);
    }
}

class FinishingWorker extends AbsWorker{

    @Override
    public String execute(String command){
        if (command.equals("glue wallpaper")){
            return "the interior decoration worker executed the command: " + command;
        }
        return super.execute(command);
    }
}

public class Main {

    public static void main(String[] args){
        Designer designer = new Designer();
        Carpenters carpenters = new Carpenters();
        FinishingWorker finishingWorker = new FinishingWorker();

        designer.setNextWorker(carpenters).setNextWorker(finishingWorker);

        GiveCommand(designer, "design a house");
        GiveCommand(designer, "laying a brick");
        GiveCommand(designer, "glue wallpaper");

        GiveCommand(designer, "conduct the transaction");
    }

    private static void GiveCommand(IWorker worker, String command){
        String str = worker.execute(command);
        if (str.equals(""))
            System.out.println("no one knows how to do");
        System.out.println(str);
    }
}