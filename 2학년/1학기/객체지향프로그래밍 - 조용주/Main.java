import java.awt.Point;

class Rectangle{
    static final int WIDTH = 50;
    static final int HEIGHT = 50;
    private Point upperLeft;
    private Point lowerRight;

    Rectangle(Point uL){
        upperLeft = uL;
        lowerRight = new Point(uL.x + WIDTH, uL.y + HEIGHT);
    }
    Rectangle(Point uL, Point lR){
        upperLeft = uL;
        lowerRight = lR;
    }
    void translate(int x, int y) {
        upperLeft.translate(x, y);
        lowerRight.translate(x, y);
    }

    public String toString() {
        return "UL: " + upperLeft + ", LR: " + lowerRight;
    }
}

class Block {
    protected Rectangle[] rectangles;

    public Block(Rectangle[] rectangles) {
        this.rectangles = rectangles;
    }

    public void translate(int x, int y) {
        for(Rectangle rect : rectangles) {
            rect.translate(x, y);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(Rectangle rect : rectangles) {
            sb.append(rect.toString()).append("\n");
        }
        return sb.toString();
    }
}

class Block1 extends Block {
    public Block1(Point p) {
        super(new Rectangle[] {
                new Rectangle(p),
                new Rectangle(new Point(p.x + Rectangle.WIDTH,p.y)),
                new Rectangle(new Point(p.x,p.y + Rectangle.HEIGHT)),
                new Rectangle(new Point(p.x + Rectangle.WIDTH,p.y + Rectangle.HEIGHT))
        });
    }

    public Block1(int x, int y) {
        this(new Point(x, y));
    }
}

class Block2 extends Block {
    public Block2(Point p) {
        super(new Rectangle[] {
                new Rectangle(p),
                new Rectangle(new Point(p.x, p.y + Rectangle.HEIGHT)),
                new Rectangle(new Point(p.x, p.y + Rectangle.HEIGHT * 2)),
                new Rectangle(new Point(p.x, p.y + Rectangle.HEIGHT * 3))
        });
    }

    public Block2(int x, int y) {
        this(new Point(x, y));
    }
}

public class Main {
    public static void main(String[] args) {
        Block1 b = new Block1(10, 10);
        Rectangle r = new Rectangle(new Point(10, 10));
        Rectangle r2 = new Rectangle(new Point(20, 20), new Point(70, 70));

        System.out.println("r");
        System.out.println(r);
        System.out.println("r2");
        System.out.println(r2);

        System.out.println("b");
        System.out.println(b);
        b.translate(10, -10);
        System.out.println("b");
        System.out.println(b);
    }
}
