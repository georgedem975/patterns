abstract class State{
    protected TrafficLight trafficLight;

    public void setTrafficLight(TrafficLight trafficLight){
        this.trafficLight = trafficLight;
    }

    public abstract void nextState();

    public abstract void previousState();
}

class TrafficLight{
    private State state;

    public TrafficLight(State st){
        setState(st);
    }

    public void setState(State st){
        state = st;
        state.setTrafficLight(this);
    }

    public void nextState(){
        state.nextState();
    }

    public void previousState(){
        state.previousState();
    }
}

class GreenState extends State{
    @Override
    public void nextState(){
        System.out.println("from green to yellow");
        trafficLight.setState(new YellowState());
    }

    @Override
    public void previousState(){
        System.out.println("green color");
    }
}

class YellowState extends State{
    @Override
    public void nextState(){
        System.out.println("from yellow to red");
        trafficLight.setState(new RedState());
    }

    @Override
    public void previousState(){
        System.out.println("from yellow to green");
        trafficLight.setState(new GreenState());
    }
}

class RedState extends State{
    @Override
    public void nextState(){
        System.out.println("red color");
    }
    
    @Override
    public void previousState(){
        System.out.println("from red to yellow");
        trafficLight.setState(new YellowState());
    }
}

public class Main {
    public static void main(String[] args){
        TrafficLight trafficLight = new TrafficLight(new GreenState());

        trafficLight.nextState();
        trafficLight.nextState();
        trafficLight.nextState();
        trafficLight.previousState();
        trafficLight.previousState();
        trafficLight.previousState();
    }
}