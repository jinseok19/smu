// javac -encoding utf-8 TestWords.java
class TestWords {
    public static void main(String[] args) {
        Words words = new Words(3, 3, 3);
        words.addNoun(new Noun("Student", "students"));
        words.addVerb(new Verb("speak", "spoke", "Spoken"));
        words.addPreposition(new Preposition("into"));
        words.countIfInNouns("students"); // should be counted
        words.countIfInNouns("Apple"); // not counted
        words.countIfInVerbs("Spoke"); // counted
        words.countIfInVerbs("Speaking"); // not counted
        words.countIfInPrepositions("Into"); // counted
        words.countIfInPrepositions("with"); // not counted
        // 명사
        // student: 1
        // Num of nouns found = 1
        // 동사
        // speak: 1
        // Num of verbs found = 1
        // 전치사
        // into: 1
        // Num of prepositions found = 1
        words.print();
    }
}