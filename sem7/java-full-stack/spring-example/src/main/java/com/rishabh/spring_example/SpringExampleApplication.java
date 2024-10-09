package com.rishabh.spring_example;

import org.springframework.boot.SpringApplication;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SpringExampleApplication {

	public static void main(String[] args) {

		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("config.xml");
		List<Student> students = new ArrayList<>();
		Scanner scanner = new Scanner(System.in);

		while (true) {
			System.out.println("Enter student ID (or '-1' to stop): ");
			int id = scanner.nextInt();
			if (id == -1) {
				break;
			}

			scanner.nextLine(); // Consume newline left-over
			System.out.println("Enter student name: ");
			String name = scanner.nextLine();

			// Create a new Student bean
			Student student = (Student) context.getBean("student");
			student.setId(id);
			student.setName(name);
			students.add(student);

			System.out.println("Added: " + student);
		}

		System.out.println("All students: ");
		for (Student s : students) {
			System.out.println(s);
		}

		context.close();
		scanner.close();
	}

}
