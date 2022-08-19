interface IProcessor{
    void process();
}

class Transmitter implements IProcessor{
    private String data;

    public Transmitter(String data){
        this.data = data;
    }

    @Override
    public void process(){
        System.out.println("Data " + data + " transmitted via the communication channel");
    }
}

abstract class Shell implements IProcessor{
    protected IProcessor processor;

    public Shell(IProcessor processor){
        this.processor = processor;
    }

    public void process(){
        processor.process();
    }
}

class HammingCoder extends Shell{
    public HammingCoder(IProcessor processor){
        super(processor);
    }

    @Override
    public void process(){
        System.out.print("noise-resistant Hamming code has been applied->");
        processor.process();
    }
}

class Encryptor extends Shell{
    public Encryptor(IProcessor processor){
        super(processor);
    }
    
    @Override
    public void process(){
        System.out.print("data encryption->");
        processor.process();
    }
}

public class Main{
    public static void main(String[] args){
        IProcessor transmitter = new Transmitter("12345");
        transmitter.process();
        System.out.println();

        Shell hammingCoder = new HammingCoder(transmitter);
        hammingCoder.process();
        System.out.println();

        Shell encryptor = new Encryptor(hammingCoder);
        encryptor.process();
    }
}