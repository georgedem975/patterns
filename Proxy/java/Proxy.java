import java.util.HashMap;
import java.util.Map;

interface ISite{
    String getPage(int num);
}

class Site implements ISite{
    public String getPage(int num){
        return "page " + num;
    }
}

class SiteProxy implements ISite{
    private ISite site;
    
    private Map<Integer, String> cache;

    public SiteProxy(ISite site){
        this.site = site;
        cache = new HashMap<>();
    }

    public String getPage(int num){
        String page;
        if (cache.containsKey(num)){
            page = cache.get(num);
            page = "from cache " + page;
        }
        else{
            page = site.getPage(num);
            cache.put(num, page);
        }
        return page;
    }
}

public class Main{
    public static void main(String[] args){
        ISite mySite = new SiteProxy(new Site());

        System.out.println(mySite.getPage(1));
        System.out.println(mySite.getPage(2));
        System.out.println(mySite.getPage(3));

        System.out.println(mySite.getPage(2));
    }
}