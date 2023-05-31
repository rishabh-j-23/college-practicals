class Shape { //prac5
    int a;
    void draw() {
    }
    void display() {
        System.out.println("hello");
    }
}
class Circle extends Shape {
    void draw() {
        System.out.println("Circle.....");
    }
    void display() {
        System.out.println("This is circle");
    }
}
class Square extends Shape {
    void draw() {
        System.out.println("Square.....");
    }
    void display() {
        System.out.println("This is square");
    }
}
public class Prac4 {
    public static void main(String[] args) {
        Circle cis = new Circle();
        Square sq = new Square();
        sq.draw();
        sq.display();
        cis.draw();
        cis.display();
    }
}
