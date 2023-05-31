class Constructor{
    int a, b;
    Constructor(int x, int y){
        a = x;
        b = y;
    }
}
public class prac2 {
    public static void main(String[] args) {
        Constructor cons = new Constructor(10, 20);
        System.out.println(cons.a);
        System.out.println(cons.b);
        
    }
}
