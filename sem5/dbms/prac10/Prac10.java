import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Prac10 {
    public static void main(String[] args){  
         
        String url = "jdbc:mysql://localhost:3306/Prac10"; 
        String user = "rishabh"; 
        String password = "rishabh"; 
        try { 
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/prac10", user, password);
            Statement statement = connection.createStatement();  
            String sqlQuery = "SELECT * FROM customers" ; 
            ResultSet resultSet = statement.executeQuery(sqlQuery);  
            while (resultSet.next()) { 
                int id = resultSet.getInt(1); 
                String name = resultSet.getString(2);  
                
                System.out.println("ID: " + id + ", Name: " + name);
            }  
            resultSet.close(); 
            statement.close(); 
            connection.close(); 
        } catch (Exception e) { 
            e.printStackTrace(); 
        } 
    }
}