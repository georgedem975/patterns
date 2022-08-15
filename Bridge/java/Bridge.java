interface IDataReader{
    void read();
}

class DataBaseReader implements IDataReader{
    @Override
    public void read(){
        System.out.print("data from the database ");
    }
}

class FileReader implements IDataReader{
    @Override
    public void read(){
        System.out.print("data from the file ");
    }
}

abstract class Sender{
    protected IDataReader reader;
    
    public Sender(IDataReader dataReader){
        reader = dataReader;
    }
    
    public void setDataReader(IDataReader dataReader){
        reader = dataReader;
    }
    
    public abstract void send();
}

class EmailSender extends Sender{
    public EmailSender(IDataReader dataReader){
        super(dataReader);
    }
    
    @Override
    public void send(){
        reader.read();
        System.out.println("sent by email");
    }
}

class TelegramBotSender extends Sender{
    public TelegramBotSender(IDataReader dataReader){
        super(dataReader);
    }
    
    @Override
    public void send(){
        reader.read();
        System.out.println("sent by telegram bot");
    }
}

public class Main{
    public static void main(String[] args){
        Sender sender = new EmailSender(new DataBaseReader());
        sender.send();

        sender.setDataReader(new FileReader());
        sender.send();

        sender = new TelegramBotSender(new DataBaseReader());
        sender.send();
    }
}