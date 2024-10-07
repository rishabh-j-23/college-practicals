package prac10.src.main.java.com.dbmsprac10;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {
    
    public static void main(String[] args) {

        String user = "root";
        String password = "rishabh";
        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/prac8", user, password);
            Statement statement = connection.createStatement();
            String sqlQuery = "SELECT * FROM customers";
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