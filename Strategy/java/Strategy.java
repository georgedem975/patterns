interface Reader{
    void parse(String url);
}

class ResourceReader{
    private Reader reader;

    public ResourceReader(Reader reader){
        this.reader = reader;
    }

    public void setStrategy(Reader reader){
        this.reader = reader;
    }

    public void read(String url){
        reader.parse(url);
    }
}

class NewsSiteReader implements Reader{
    public void parse(String url){
        System.out.println("parse site " + url);
    }
}

class SocialNetworkReader implements Reader{
    public void parse(String url){
        System.out.println("parse social networks " + url);
    }
}

class TelegramChannelReader implements Reader{
    public void parse(String url){
        System.out.println("parse telegram channel " + url);
    }
}

public class Main{
    public static void main(String[] args){
        ResourceReader resourceReader = new ResourceReader(new NewsSiteReader());

        String url = "news site";
        resourceReader.read(url);

        url = "social network";
        resourceReader.setStrategy(new SocialNetworkReader());
        resourceReader.read(url);

        url = "telegram channel";
        resourceReader.setStrategy(new TelegramChannelReader());
        resourceReader.read(url);
    }
}