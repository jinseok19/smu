import java.util.Arrays;
import java.util.Scanner;

public class StringsHashValues {
    private String[] words;
    private int[] hashValues;

    public void printWordsWithSameHash(String w) {
        boolean temp = false;
        for (int i = 0; i < words.length; i++) {
            if (getHashValue(w) == hashValues[i]) {
                System.out.println(words[i]);
                temp = true;
            }
        }
        if(!temp){
            System.out.println("해시값이 일치하는 단어가 없습니다.");
        }
            }


    public StringsHashValues(String input) {
        // split the input string into words
        words = input.split(" "); // 공백 기준으로 분리 저장

        // create an array to store hash values
        hashValues = new int[words.length]; // 배열의 크기를 단어의 길이로 생성
        //System.out.printf("문자열 길이 %d\n", words.length);

        // calculate hash value for each word
        for (int i = 0; i < words.length; i++) {
            if (!words[i].isEmpty()) { // 단어가 공백이거나 null 값이 아니면
                // hash 값을 hashValues 배열에 새롭게 저장
                hashValues[i] = getHashValue(words[i]);
            }
        }
    }

    private int getHashValue(String s) {
        int hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash += (s.charAt(i) * Math.pow(31,s.length()-1)) % s.length();
        }
        return hash;
    }

    public int[] getHashValues() { // hash 값을 hashValues라는 배열에 저장
        return hashValues;
    }

    public static void main(String[] args) {
        StringsHashValues shv = new StringsHashValues("In blandit lacus ac sapien dictum, elementum" +
                "fringilla sem varius. Vestibulum consectetur" +
                "metus at felis porttitor, a rhoncus neque" +
                "consectetur. Integer vehicula felis non metus" +
                "eleifend, in blandit risus ullamcorper. Phasellus" +
                "mauris nisi, facilisis et quam placerat, congue" +
                "venenatis diam. Praesent in erat odio. Phasellus" +
                "sit amet efficitur sem. Ut quis mi venenatis," +
                "feugiat justo eu, rhoncus velit. Suspendisse" +
                "iaculis tempus sapien. Integer mauris neque," +
                "posuere sed mi at, aliquet facilisis nibh. Cras" +
                "vel blandit lorem. Aliquam suscipit, nisl id" +
                "condimentum condimentum, purus magna maximus" +
                "sem, vitae vehicula diam nisi ac enim.");

        // hash 값 생성
        int[] hashValues = shv.getHashValues();
        //System.out.println(Arrays.toString(hashValues));
        // 입력 받는 부분
        Scanner sc = new Scanner(System.in);
        System.out.print("문자 입력: ");
        String word = sc.next();
        // 값은 hash 값을 가진 단어 출력 함수
        shv.printWordsWithSameHash(word);
    }
}





