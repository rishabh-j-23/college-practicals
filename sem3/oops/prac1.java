class Calculate {
    public int add(int a, int b){
        return a + b;
    }
    public int multiply(int a, int b){
        return a * b;
    }
    public int subtract(int a, int b){
        return a - b;
    }
}

public class prac1 {
    public static void main(String[] args) throws Exception {
        Calculate calc = new Calculate();
        System.out.println(calc.add(10, 13));
        System.out.println(calc.subtract(40, 28));
        System.out.println(calc.multiply(38, 42));
    }
}
