abstract class Shape {
    abstract void draw();
    abstract void colour();
    abstract void area();
}

class Circle extends Shape {
    int radius;

    Circle(int rad) {
        radius = rad;
    }

    void circumference() {
        System.out.println("Circumference of Circle is");
        System.out.println(2 * 3.14 * radius);
    }
    @Override
    void area() {
        System.out.println("area of Circle is");
        System.out.println(3.14 * radius * radius);
    }
    @Override
    void draw() {
        System.out.println("Circle");
    }
    @Override
    void colour() {
        System.out.println("Red");
    }
}

class Square extends Shape {
    int side1;

    Square(int side) {
        side1 = side;
    }

    void perimeter() {
        System.out.println("perimeter of Square is");
        System.out.println(4 * side1);
    }
    @Override
    void area() {
        System.out.println("area of Square is");
        System.out.println(side1 * side1);
    }
    @Override
    void draw() {
        System.out.println("Square");
    }
    @Override
    void colour() {
        System.out.println("blue");
    }
}

public class Prac5 {
    public static void main(String[] args) {
        Circle cir = new Circle(10);
        Square sq = new Square(10);
        cir.draw();
        cir.colour();
        cir.area();
        cir.circumference();
        sq.draw();
        sq.colour();
        sq.area();
        sq.perimeter();
    }
}
