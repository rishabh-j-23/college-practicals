package io.rishabh.prac5;

public class Employee {
    
    private String empId;
    private String firstName;
    private String lastName;
    private String email;
    private String gender;
    private String newJoiner;
    private int salary;
    private int rating;
   public Employee(String empId, String firstName, String lastName, String email, String gender, String newJoiner,
           int salary, int rating) {
       this.empId = empId;
       this.firstName = firstName;
       this.lastName = lastName;
       this.email = email;
       this.gender = gender;
       this.newJoiner = newJoiner;
       this.salary = salary;
       this.rating = rating;
   }
   public String getEmpId() {
       return empId;
   }
   public String getFirstName() {
       return firstName;
   }
   public String getLastName() {
       return lastName;
   }
   public String getEmail() {
       return email;
   }
   public String getGender() {
       return gender;
   }
   public String getNewJoiner() {
       return newJoiner;
   }
   public int getSalary() {
       return salary;
   }
   public int getRating() {
       return rating;
   }

    @Override
    public String toString() {
        return "Employee [empId=" + empId + ", firstName=" + firstName + ", lastName=" + lastName + ", email=" + email
                + ", gender=" + gender + ", newJoiner=" + newJoiner + ", salary=" + salary + ", rating=" + rating + "]";
    }
    public String getNewJoining() {
        return this.newJoiner;
    }
}