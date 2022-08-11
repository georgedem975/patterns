interface IMediator{
    void notify(Employee employee, String msg);
}

abstract class Employee{
    protected IMediator mediator;

    public Employee(IMediator mediator){
        this.mediator = mediator;
    }
    
    public void setMediator(IMediator mediator){
        this.mediator = mediator;
    }
}

class Designer extends Employee{
    private boolean isWorking;
    
    public Designer(IMediator mediator){
        super(mediator);
    }
    
    public void executeWork(){
        System.out.println("<-the designer is at work");
        mediator.notify(this, "the designer designs...");
    }
    
    public void setWork(boolean state){
        isWorking = state;
        if (state)
            System.out.println("<-the designer is released from work");
        else
            System.out.println("<-the designer is busy");
    }
}

class Director extends Employee{
    private String text;
    
    public Director(IMediator mediator){
        super(mediator);
    }
    
    public void giveCommand(String txt){
        text = txt;
        if (text == "")
            System.out.println("->the director knows that the designer is already working");
        else
            System.out.println("->the director gave the command:" + text);
        mediator.notify(this, text);
    }
}

class Controller implements IMediator{
    private Designer designer;
    private Director director;
    
    public Controller(Designer designer, Director director){
        this.designer = designer;
        this.director = director;
        designer.setMediator(this);
        director.setMediator(this);
    }
    
    @Override
    public void notify(Employee employee, String msg){
        if (employee instanceof Director) {
            if (msg.equals(""))
                designer.setWork(false);
            else
                designer.setWork(true);
        }
        if (employee instanceof Designer)
            director.giveCommand("");
    }
}

public class Main {
    public static void main(String[] args){
        Designer designer = new Designer(null);
        Director director = new Director(null);

        Controller mediator = new Controller(designer, director);

        director.giveCommand("design");

        System.out.println();

        designer.executeWork();
    }
}