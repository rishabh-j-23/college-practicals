package io.rishabh.prac3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

class Employee {
    String ssn;
    String firstName;
    String lastName;
    String email;
    String gender;
    boolean isActive;
    double salary;
    int experience;

    public Employee(String ssn, String firstName, String lastName, String email, String gender,
            boolean isActive, double salary, int experience) {
        this.ssn = ssn;
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
        this.gender = gender;
        this.isActive = isActive;
        this.salary = salary;
        this.experience = experience;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "ssn='" + ssn + '\'' +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", email='" + email + '\'' +
                ", gender='" + gender + '\'' +
                ", isActive=" + isActive +
                ", salary=" + salary +
                ", experience=" + experience +
                '}';
    }
}

public class JdbcConnection {

    private static final String URL = "jdbc:mysql://localhost:3306/jfsd";
    private static final String USER = "rish";
    private static final String PASSWORD = "rishabh";

    public static void main(String[] args) throws ClassNotFoundException {
        Employee[] employees = {
                new Employee("59-385-1088", "Zacharias", "Schwerin", "zchwerin@gmail.com", "Male", true, 101146, 0),
                new Employee("73-274-6476", "Kyle", "Frudd", "kfrudd1@ovh.net", "Male", false, 29310, 2),
                new Employee("85-939-9584", "Axe", "Gumb", "agumb2@twitter.com", "Female", false, 62291, 4),
                new Employee("08-180-8292", "Robinet", "Batterham", "rbatterham3@last.fm", "Male", false, 142439, 4),
                new Employee("21-825-2623", "Ulick", "Burrel", "uburrel4@google.ru", "Male", false, 128764, 5),
                new Employee("66-708-5539", "Tailor", "Ridding", "Ridding", "Female", false, 152924, 4),
                new Employee("81-697-2363", "Joete", "Braybrooke", "jbraybrooke6@prnewswire.com", "Male", true, 128907,
                        0),
                new Employee("63-019-1110", "Elroy", "Baverstock", "ebaverstock7@ehow.com", "Male", true, 2510, 0)
        };

        Class.forName("com.mysql.cj.jdbc.Driver");

        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD)) {
            // Fetch and display employee records
            fetchEmployees(connection);

            // Insert new employee records
            for (Employee employee : employees) {
                insertEmployee(connection, employee);
            }

            // Fetch and display updated employee records
            fetchEmployees(connection);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void fetchEmployees(Connection connection) {
        String selectSQL = "SELECT * FROM employee";
        try (PreparedStatement statement = connection.prepareStatement(selectSQL);
                ResultSet resultSet = statement.executeQuery()) {

            System.out.println("Employee Records:");
            while (resultSet.next()) {
                String ssn = resultSet.getString("ssn");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String email = resultSet.getString("email");
                String gender = resultSet.getString("gender");
                boolean isActive = resultSet.getBoolean("is_active");
                double salary = resultSet.getDouble("salary");
                int experience = resultSet.getInt("experience");

                Employee employee = new Employee(ssn, firstName, lastName, email, gender, isActive, salary, experience);
                System.out.println(employee);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void insertEmployee(Connection connection, Employee employee) {
        String insertSQL = "INSERT INTO employee (ssn, first_name, last_name, email, gender, is_active, salary, experience) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(insertSQL)) {
            statement.setString(1, employee.ssn);
            statement.setString(2, employee.firstName);
            statement.setString(3, employee.lastName);
            statement.setString(4, employee.email);
            statement.setString(5, employee.gender);
            statement.setBoolean(6, employee.isActive);
            statement.setDouble(7, employee.salary);
            statement.setInt(8, employee.experience);

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("A new employee was inserted successfully!");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
