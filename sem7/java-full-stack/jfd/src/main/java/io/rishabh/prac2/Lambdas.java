package io.rishabh.prac3;

interface Sum {
    void sum(int a, int b);
}

interface Diff {
    void diff(int a, int b);
}

public class Lambdas {
    public static void main(String[] args) {
        int a = 4, b = 3;
        Sum s = (x, y) -> System.out.println(x+y);
        s.sum(a, b);

        Diff d = (x, y) -> System.out.println(x-y);
        d.diff(a, b);
    }   
}
