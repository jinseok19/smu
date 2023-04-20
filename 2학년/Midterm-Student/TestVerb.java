// javac -encoding utf-8 TestVerb.java Words.java
class TestVerb {
    public static void main(String[] args) {
        Verb v = new Verb("speak", "Spoke", "Spoken");
        if (v.equals("Speak")) {
            v.increaseCount();
        }
        if (v.equals("Spoke")) {
            v.increaseCount();
        }
        if (v.equals("Spoken")) {
            v.increaseCount();
        }
        if (v.equals("Speaking")) {
            v.increaseCount();
        }
        v.print(); // speak: 3 출력
    }
}