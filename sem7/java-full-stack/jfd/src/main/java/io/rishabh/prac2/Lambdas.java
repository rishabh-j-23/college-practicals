package io.rishabh.prac2;

interface Sum {
    void sum(int a, int b);
}

interface Factorial {
    void factorial(int a);
}

public class Lambdas {
    public static void main(String[] args) {
        int a = 4, b = 3;
        System.out.println("a: " + a + " b: " + b);
        Sum s = (x, y) -> System.out.println(x + y);
        System.out.print("Sum: ");
        s.sum(a, b);

        Factorial f = (x) -> {
            int fact = 1;
            for (int i = 1; i <= x; i++) {
                fact *= i;
            }
            System.out.println(fact);
        };
        System.out.print("Factorial: ");
        f.factorial(a);
    }
}
