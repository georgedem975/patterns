class Phone{
    String data;
    
    public Phone(){
        data = "";
    }
    
    public String aboutPhone(){
        return data;
    }
    
    public void appendData(String str){
        data += str;
    }
}

interface IDeveloper{
    void createDisplay();
    
    void createBox();
    
    void systemInstall();
    
    Phone getPhone();
}

class AndroidDeveloper implements IDeveloper{
    private Phone phone;
    
    public AndroidDeveloper(){
        phone = new Phone();
    }
    
    @Override
    public void createDisplay(){
        phone.appendData("(create) display Samsung; ");
    }
    
    @Override
    public void createBox(){
        phone.appendData("(create) corpus Samsung; ");
    }
    
    @Override
    public void systemInstall(){
        phone.appendData("(install) system Android; ");
    }
    
    @Override
    public Phone getPhone(){
        return phone;
    }
}

class IphoneDeveloper implements IDeveloper{
    private Phone phone;
    
    public IphoneDeveloper(){
        phone = new Phone();
    }
    
    @Override
    public void createDisplay(){
        phone.appendData("(create) display Iphone; ");
    }
    
    @Override
    public void createBox(){
        phone.appendData("(create) corpus Iphone; ");
    }
    
    @Override
    public void systemInstall(){
        phone.appendData("(install) system IOS; ");
    }
    
    @Override
    public Phone getPhone(){
        return phone;
    }
}

class Director{
    private IDeveloper developer;
    
    public Director(IDeveloper developer){
        this.developer = developer;
    }
    
    public void setDeveloper(IDeveloper developer){
        this.developer = developer;
    }
    
    public Phone MountOnlyPhone(){
        developer.createBox();
        developer.createDisplay();
        return developer.getPhone();
    }
    
    public Phone MountFullPhone(){
        developer.createBox();
        developer.createDisplay();
        developer.systemInstall();
        return developer.getPhone();
    }
}

public class Main {
    public static void main(String[] args){
        IDeveloper developer = new AndroidDeveloper();

        Director director = new Director(developer);

        Phone samsung = director.MountFullPhone();
        System.out.println(samsung.aboutPhone());

        IDeveloper iphoneDeveloper = new IphoneDeveloper();
        director.setDeveloper(iphoneDeveloper);

        Phone iphone = director.MountOnlyPhone();
        System.out.println(iphone.aboutPhone());
    }
}