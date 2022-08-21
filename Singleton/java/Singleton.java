class DatabaseHelper{
    private String data;
    
    private static DatabaseHelper databaseConnection;
    
    private DatabaseHelper(){
        System.out.println("connecting to the database");
    }
    
    public static DatabaseHelper getConnection(){
        if (databaseConnection == null)
            databaseConnection = new DatabaseHelper();
        return databaseConnection;
    }
    
    public String selectData(){
        return data;
    }
    
    public void insertData(String d){
        System.out.println("new data: " + d + "(entered into the database)");
        data = d;
    }
}

public class Main{
    public static void main(String[] args){
        DatabaseHelper.getConnection().insertData("123");
        System.out.println("Data: " + DatabaseHelper.getConnection().selectData());
    }
}