// javac -encoding utf-8 TestNoun.java Words.java
class TestNoun {
    public static void main(String[] args) {
        Noun noun = new Noun("Student", "students");        
        if (noun.equals("student")) {
            noun.increaseCount();
        }
        if (noun.equals("students")) {
            noun.increaseCount();
        }
        noun.print(); // student: 2 출력
    }
}