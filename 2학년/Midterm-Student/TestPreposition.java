// javac -encoding utf-8 TestPreposition.java Words.java
class TestPreposition {
    public static void main(String[] args) {
        Preposition p = new Preposition("into");
        if (p.equals("Into")) {
            p.increaseCount();
        }
        if (p.equals("inTo")) {
            p.increaseCount();
        }
        if (p.equals("into")) {
            p.increaseCount();
        }
        p.print(); // into: 3 출력
    }
}