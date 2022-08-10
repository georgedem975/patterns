abstract class Transmitter{
    protected void voiceRecord(){
        System.out.println("recording a fragment of speech");
    }

    protected void simpling(){

    }

    protected void digitization(){

    }

    protected void modulation(){

    }

    protected void transmission(){
        System.out.println("signal transmission via radio channel");
    }

    public void ProcessStart(){
        voiceRecord();
        simpling();
        digitization();
        modulation();
        transmission();
    }
}

class AnalogTransmitter extends Transmitter{
    @Override
    protected void modulation(){
        System.out.println("modulation of the analog signal");
    }
}

class DigitTransmitter extends Transmitter{
    @Override
    protected void simpling(){
        System.out.println("sampling of the recorded fragment");
    }

    @Override
    protected void digitization(){
        System.out.println("digitization");
    }
    
    @Override
    protected void modulation(){
        System.out.println("digital signal modulation");
    }
}

public class Main {
    public static void main(){
        
        Transmitter analogTransmitter = new AnalogTransmitter();
        analogTransmitter.ProcessStart();

        System.out.println();

        Transmitter digitTransmitter = new DigitTransmitter();
        digitTransmitter.ProcessStart();
    }
}