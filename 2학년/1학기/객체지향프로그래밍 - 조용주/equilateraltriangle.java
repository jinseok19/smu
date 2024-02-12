import java.util.Scanner;// 외부 패키지 클래스


public class equilateraltriangle {
    public int x1, y1, x2, y2;

    public equilateraltriangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public double getDistance() {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

    public double getArea() {

        double a = getDistance();

        return (Math.sqrt(3)/Math.sqrt(4))*Math.pow(a,2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("T1의 좌표 값을 입력하세요!");
        System.out.print("x1: ");
        int x1 = scanner.nextInt();
        System.out.print("y1: ");
        int y1 = scanner.nextInt();

        System.out.println("T2의 좌표 값을 입력하세요!");
        System.out.print("x2: ");
        int x2 = scanner.nextInt();
        System.out.print("y2: ");
        int y2 = scanner.nextInt();

        equilateraltriangle triangle = new equilateraltriangle(x1, y1, x2, y2);
        System.out.println("정 삼각형 넓이: " + triangle.getArea());

        scanner.close();
    }
}