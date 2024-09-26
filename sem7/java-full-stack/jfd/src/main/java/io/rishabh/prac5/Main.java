package io.rishabh.prac5;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {

        List<Employee> empList = getEmpList();

        // i. Filter the employees list with gender as Female
        System.out.println("Employees with Gender as Female:");
        empList.stream()
                .filter(e -> e.getGender().equalsIgnoreCase("Female"))
                .forEach(e -> System.out.println(e.getEmail()));
        System.out.println();

        // ii. Filter the employees list with newJoiner as True
        System.out.println("Employees who are New Joiners:");
        empList.stream()
                .filter(e -> e.getNewJoining().equalsIgnoreCase("True"))
                .forEach(e -> System.out.println(e.getFirstName()));
        System.out.println();

        // iii. Sort the employee list by rating ascending
        System.out.println("Employees sorted by Rating (Ascending):");
        empList.stream()
                .sorted(Comparator.comparing(Employee::getRating))
                .forEach(e -> System.out.println(e.getFirstName()));
        System.out.println();

        // iv. Sort the employee list by both rating and salary
        System.out.println("Employees sorted by Rating and Salary:");
        empList.stream()
                .sorted(Comparator.comparing(Employee::getRating).thenComparing(Employee::getSalary))
                .forEach(e -> System.out.println(e.getFirstName()));
        System.out.println();

        // v. Retrieve employee with max salary
        System.out.println("Employee with Max Salary:");
        empList.stream()
                .max(Comparator.comparing(Employee::getSalary))
                .ifPresent(System.out::println);
        System.out.println();

        // vi. Retrieve employee with min salary
        System.out.println("Employee with Min Salary:");
        empList.stream()
                .min(Comparator.comparing(Employee::getSalary))
                .ifPresent(System.out::println);
        System.out.println();

        // vii. Group all employees by Gender
        System.out.println("Employees grouped by Gender:");
        Map<String, List<Employee>> employeesByGender = empList.stream()
                .collect(Collectors.groupingBy(Employee::getGender));

        employeesByGender.forEach((gender, employees) -> {
            System.out.println(gender + ":");
            employees.forEach(emp -> System.out.println(emp.getFirstName()));
        });
    }

    public static List<Employee> getEmpList() {
        return Arrays.asList(
                new Employee("59-385-1088", "Zacharias", "Schwerin", "zchwerin@gmail.com", "Male", "True", 101146, 0),
                new Employee("73-274-6476", "Kyle", "Frudd", "kfrudd1@ovh.net", "Male", "False", 29310, 2),
                new Employee("85-939-9584", "Axe", "Gumb", "agumb2@twitter.com", "Female", "False", 62291, 4),
                new Employee("08-180-8292", "Robinet", "Batterham", "rbatterham3@last.fm", "Male", "False", 142439, 4),
                new Employee("21-825-2623", "Ulick", "Burrel", "uburrel4@google.ru", "Male", "False", 128764, 5),
                new Employee("66-708-5539", "Tailor", "Ridding", "Ridding", "Female", "False", 152924, 4),
                new Employee("81-697-2363", "Joete", "Braybrooke", "jbraybrooke6@prnewswire.com", "Male", "True",
                        128907, 0),
                new Employee("63-019-1110", "Elroy", "Baverstock", "ebaverstock7@ehow.com", "Male", "True", 2510, 0));
    }
}
