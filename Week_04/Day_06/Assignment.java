
// 1. Interface Example

interface Test {
    int square(int n);
}

class Arithmetic implements Test {
    public int square(int n) {
        return n * n;
    }
}

// 2. Outer and Inner Class

class Outer {

    void display() {
        System.out.println("Display method of Outer class");
    }

    class Inner {

        void display() {
            System.out.println("Display method of Inner class");
        }
    }
}

// 3. Point Class

class Point {

    private int x;
    private int y;

    // Default Constructor
    public Point() {
        x = 0;
        y = 0;
    }

    // Parameterized Constructor
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void display() {
        System.out.println("Point Coordinates: (" + x + ", " + y + ")");
    }
}

// 4. Box and Box3D

class Box {

    double length;
    double breadth;

    Box(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    double area() {
        return length * breadth;
    }
}

class Box3D extends Box {

    double height;

    Box3D(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    double volume() {
        return length * breadth * height;
    }
}

// Main Class

public class Assignment {

    public static void main(String[] args) {

        System.out.println("===== PROGRAM 1 : Interface =====");
        Arithmetic arithmetic = new Arithmetic();
        System.out.println("Square of 5 = " + arithmetic.square(5));

        System.out.println("\n===== PROGRAM 2 : Outer and Inner Class =====");
        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();

        System.out.println("\n===== PROGRAM 3 : Point Class =====");

        Point p1 = new Point();
        p1.display();

        p1.setX(10);
        p1.setY(20);
        p1.display();

        p1.setXY(30, 40);
        p1.display();

        Point p2 = new Point(50, 60);
        p2.display();

        System.out.println("\n===== PROGRAM 4 : Box and Box3D =====");

        Box box = new Box(10, 5);
        System.out.println("Area of Box = " + box.area());

        Box3D box3d = new Box3D(10, 5, 2);
        System.out.println("Volume of Box3D = " + box3d.volume());
    }
}
