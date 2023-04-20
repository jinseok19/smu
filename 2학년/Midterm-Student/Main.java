public class Main {
    // 문자열의 단어 개수를 정확하게 모르기 때문에 배열의 크기를 넉넉하게 지정
    int MAX_SPEECH_WORDS = 200;
    Words words;

    // 명사는 단수형과 복수형으로 두 개씩 쌍으로
    String[] nouns = { "hope", "hopes", "application", "applications",
            "life", "lives", "year", "years",
            "computer", "computers", "college", "colleges",
            "typography", "typographies", "course", "courses",
            "typeface", "typefaces", "font", "fonts",
            "calligraphy", "calligraphy", "dot", "dots" };
    String[] verbs = { "have", "had", "had", "come", "came", "come",
            "drop", "dropped", "dropped", "design", "designed", "designed",
            "connect", "connected", "connected",
            "do", "did", "done", "look", "looked", "looked",
            "copy", "copied", "copied" };
    String[] prepositions = { "of", "in", "into", "with", "on" };
    int numOfSplittedWords; // 분리된 단어 개수.

    Main() {
        numOfSplittedWords = 0;
        addWords();
    }

    // Words 객체를 생성한 후, 개수를 파악하고자 하는 명사, 동사, 전치사 등을
    // Words 객체에 추가
    void addWords() {
        words = new Words(nouns.length / 2, verbs.length / 3, prepositions.length);
        for (int i = 0; i < nouns.length; i+=2) {
            words.addNoun(new Noun(nouns[i], nouns[i+1]));
        }
        for (int i = 0; i < verbs.length; i+=3) {
            words.addVerb(new Verb(verbs[i], verbs[i+1], verbs[i+2]));
        }
        for (int i = 0; i < prepositions.length; i++) {
            words.addPreposition(new Preposition(prepositions[i]));
        }
    }

    // s로 주어진 문자열의 양 끝에 있는 공백 문자를 제거한 후, 
    // 콤마나 마침표가 있으면 그것도 제거한 후에 반환
    // 문자열 양 끝에 공백 문자나 콤마, 마침표가 없으면 원본 반환 
    String trimSpecialCharAndSpace(String s) {
        s = s.trim();
        if(s.charAt(0) == ',' || s.charAt(0) =='.'){
            s = s.substring(1);
        } else if ((s.charAt(s.length()-1) == ',') || (s.charAt(s.length()-1) == '.')) {
            s = s.substring(0, s.length()-1);
        }
        return s;

    }

    // s로 주어진 문자열을 단어별로 잘라서 배열에 저장한 후 반환
    // 단어는 공백 문자(' ') 한 개로 구분됨
    String[] splitWords(String s) {
        String[] words = new String[MAX_SPEECH_WORDS]; // 분리된 단어들을 저장할 배열 생성
        
        // 나머지 변수와 코드 추가할 것
        words = s.split(" ");
        for(int i=0; i<words.length; i++){
            words[i] = trimSpecialCharAndSpace(words[i]);
            if (words[i] == null){
                break;
            }
        }

        numOfSplittedWords = words.length;


        
        // 디버깅 목적
        // length of words = 144
        // length of words = later
        System.out.printf("length of words = %d\n", numOfSplittedWords);
        System.out.printf("last word = %s\n", words[numOfSplittedWords - 1]);
        return words;
    }

    // word를 화면에 출력하기 (형태는 "word: 단어")
    // 주어진 단어가 명사, 동사, 전치사에 있는지 확인하고 개수 세기
    // Words 객체의 메소드를 이용
    void countWord(String word) {
        System.out.printf("word: %s\n", word);
        // 다음 if-else if 코드의 블록에서는 아무것도 하지 않는다.
        // 효율성을 위해서 만들어진 코드
        if (words.countIfInNouns(word)) {
            // 아무것도 안함
        }
        else if (words.countIfInVerbs(word)) {
            // 아무것도 안함
        }
        else if (words.countIfInPrepositions(word)) {
            // 아무것도 안함
        }
    }

    // Words 객체의 메소드를 이용해서 검색된 명사, 동사, 전치사와 개수를 출력하고
    // 검색된 명사, 동사, 전치사의 전체 개수를 각 품사별로 출력
    void print() {
        words.print();

    }

    int getNumOfSplittedWords() {
            return numOfSplittedWords; }

    public static void main(String[] args) {
        String speech = "None of this had even a hope of any practical "
                        + "application in my life. But 10 years later, "
                        + "when we were designing the first Macintosh"
                        + " computer, it all came back to me. And we"
                        + " designed it all into the Mac. It was the "
                        + "first computer with beautiful typography. "
                        + "If I had never dropped in on that single "
                        + "course in college, the Mac would have never "
                        + "had multiple typefaces or proportionally "
                        + "spaced fonts. And since Windows just copied "
                        + "the Mac, it is likely that no personal "
                        + "computer would have them. If I had never "
                        + "dropped out, I would have never dropped in "
                        + "on this calligraphy class, and personal "
                        + "computers might not have the wonderful typography"
                        + " that they do. Of course it was impossible to "
                        + "connect the dots looking forward when I was in "
                        + "college. But it was very, very clear looking "
                        + "backward 10 years later.";

        Main m = new Main();
        String[] words = m.splitWords(speech);
        for (int i = 0; i < m.getNumOfSplittedWords(); i++) {
            m.countWord(words[i]);
        }
        m.print();
    }
}