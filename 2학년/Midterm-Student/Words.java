class Preposition {
    String preposition; // 전치사 문자열
    int count; // preposition이 문자열에 나타난 횟수 저장

    // 전치사 문자열로 초기화
    // 횟수 초기화
    Preposition(String preposition) {
        this.preposition = preposition;
        this.count = 0;

    }

    // 주어진 word가 멤버 변수에 저장되어 있는
    // 전치사와 일치하면 true 아니면 false 반환
    boolean equals(String word) {
        return preposition.equals(word.toLowerCase());
    }

    // "전치사: 개수" 형태로 화면에 출력
    void print() {
        System.out.printf("전치사 : %d", count);
    }

    // 전치사가 나타난 횟수를 1 증가시킴
    void increaseCount() {
        count++;
    }

    //; 전치사가 나타난 횟수 반환
    int getCount() {
        return count;
    }
}

class Verb {
    String[] verbs; // 0: 현재형, 1: 과거형, 2: 과거완료형
    int count; // 동사가 문자열에 나타난 횟수 저장

    // 동사의 현재형, 과거형, 과거 분사형을 받아서 초기화
    // 횟수 초기화
    Verb(String present, String past, String pp) {
         this.verbs = new String[3];
        this.verbs[0] = present;
        this.verbs[1] = past;
        this.verbs[2] = pp;
        this.count = 0;
    }

    // 주어진 단어가 동사의 현재형, 과거형, 또는 과거 분사형과 일치하면 true,
    // 아니면 false 반환
    boolean equals(String word) {
        word = word.toLowerCase();
        return verbs[0].equals(word) ||  verbs[1].equals(word) ||  verbs[2].equals(word);
    }

    // "동사_현재_원형: 개수" 형태로 화면에 출력
    void print() {
        System.out.printf("동사_현재_원형: %d", count);

    }

    // 동사가 나타난 횟수를 1 증가시킴
    void increaseCount() {
        count++;

    }

    // 동사가 나타난 횟수 반환
    int getCount() {
        return count;
    }
}

class Noun {
    String[] nouns; // 0: 단수, 1: 복수
    int count; // 명사가 문자열에 나타난 횟수 저장

    // 명사의 단수형, 복수형 문자열로 초기화
    Noun(String singular, String plural) {
        this.nouns = new String[2];
        this.nouns[0] = singular;
        this.nouns[1] = plural;
        this.count = 0;

    }

    // 주어진 단어가 명사의 단수형 또는 복수형과 일치하면 true,
    // 아니면 false 반환
    boolean equals(String word) {
        word = word.toLowerCase();
        return nouns[0].equals(word) || nouns[1].equals(word);
    }

    // "명사_단수형: 개수" 형태로 화면에 출력
    void print() {
        System.out.printf("%s: %d\n",nouns[0],count);

    }

    // 명사가 나타난 횟수를 1 증가시킴
    void increaseCount() {
        count++;
    }

    // 명사가 나타난 횟수 반환
    int getCount() {
        return count;
    }
}

public class Words {
    Noun[] nouns; // 검색하고 나타난 횟수를 셀 명사들을 저장
    Verb[] verbs; // 검색하고 나타난 횟수를 셀 동사들을 저장
    Preposition[] prepositions; // 전치사들을 저장
    int curIdxNouns; // 명사를 추가할 때 다음에 저장할 위치 기록
    int curIdxVerbs; // 동사를 추가할 때 다음에 저장할 위치 기록
    int curIdxPrepositions; // 전치사 추가용 저장 위치 기록

    // 검색할 명사, 동사, 전치사 개수를 입력으로 전달 받고
    // 배열 생성
    // 그 밖에 다른 초기화 작업
    Words(int numNouns, int numVerbs, int numPrepositions) {

        curIdxNouns = 0;
        curIdxVerbs = 0;
        curIdxPrepositions = 0;

        nouns = new Noun[numNouns];
        verbs = new Verb[numVerbs];
        prepositions = new Preposition[numPrepositions];


    }


    // 배열에 검색할 명사 추가
    void addNoun(Noun noun) {

        nouns[curIdxNouns] = noun;
        curIdxNouns++;
    }

    // 배열에 검색할 동사 추가
    void addVerb(Verb verb) {
        verbs[curIdxVerbs] = verb;
        curIdxVerbs++;
    }

    // 배열에 검색할 전치사 추가
    void addPreposition(Preposition prepositioin) {
        prepositions[curIdxPrepositions] = prepositioin;
        curIdxPrepositions++;

    }

    // 주어진 단어 word가 명사 배열에 있으면 횟수를 1 증기시키고, true 반환
    // 아니면 false 반환
    boolean countIfInNouns(String word) {


        for (int i = 0; i < nouns.length; i++) {
            if (nouns[i].equals(word)) {
                nouns[i].increaseCount();
                return true;
            }
        }
            return false;
    }

    // 주어진 단어 word가 동사 배열에 있으면 횟수를 1 증기시키고, true 반환
    // 아니면 false 반환
    boolean countIfInVerbs(String word) {

        for (int i = 0; i < curIdxVerbs; i++) {
            if (verbs[i].equals(word)) {
                verbs[i].increaseCount();
                return true;
            }
        }
        return false;


    }

    // 주어진 단어 word가 전치사 배열에 있으면 횟수를 1 증기시키고, true 반환
    // 아니면 false 반환
    boolean countIfInPrepositions(String word) {

        for (int i = 0; i < prepositions.length; i++) {
            if (prepositions[i].equals(word)) {
                prepositions[i].increaseCount();
                return true;
            }

        }
        return false;
    }




        // 모든 명사와 개수를 화면에 출력
        // "명사"를 먼저 화면에 출력한 후,
        // 다음 줄부터 명사를 각각 한 줄에 한 개씩 화면에 출력
        // 예:
        // 명사
        // hope: 3
        // application: 2
        // ...
        void printNounCounts () {
        System.out.printf("명사");
        for(int i = 0; i < curIdxNouns; i++){
            nouns[i].print();

        }
        }

        // 모든 명사와 개수를 화면에 출력
        // "동사"를 먼저 화면에 출력한 후,
        // 다음 줄부터 동사의 현재형과 개수를 한 줄에 한 개씩 화면에 출력
        void printVerbCounts () {
            System.out.printf("동사");
            for(int i = 0; i < curIdxVerbs; i++){
                verbs[i].print();

            }
        }

        // 모든 명사와 개수를 화면에 출력
        // "동사"를 먼저 화면에 출력한 후,
        // 다음 줄부터 동사의 현재형과 개수를 한 줄에 한 개씩 화면에 출력
        void printPrepositionCounts () {
            System.out.printf("전치사");
            for(int i = 0; i < curIdxPrepositions; i++){
                prepositions[i].print();

            }
        }

        // printNounCounts(), printVerbCounts(),
        // printPrepositionCounts() 함수를 순차적으로 호출하는 유틸리티 함수
        void print () {
        printNounCounts();
        printVerbCounts();
        printPrepositionCounts();
        }
    }
