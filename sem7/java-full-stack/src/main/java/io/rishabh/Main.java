package io.rishabh;

interface Sum {
    int sum(int a, int b);
}

public class Main {
    public static void main(String[] args) {
        Sum s = (a, b) -> {
            return a + b;
        };
        System.out.println(s.sum(10, 5));
    }
}