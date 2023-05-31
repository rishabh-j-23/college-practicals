import java.util.Vector;

public class Prac8B {
    public static void main(String[] args) {
        Vector v = new Vector<>();
        //{100, 200, 300, 200, 400, 500, 600, 700};
        v.add(100);
        v.add(200);
        v.add(300);
        v.add(200);
        v.add(400);
        v.add(500);
        v.add(600);
        v.add(700);
        
        System.out.println("Vector : " + v);
        v.remove((Object)200);
        System.out.println("Vector after removing repitative occurance : " + v);
        v.remove(4);
        System.out.println("Vector after removing element at index 4 : " + v);
        System.out.println("Element at index 1 : " + v.get(1));
    }
}