import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class WordFrequencyCounter {
    public static void main(String[] args) {
        String fileName = "MP09data.txt";  // 파일 경로와 이름을 적절히 수정해주세요

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            Map<String, Integer> wordFrequency = new HashMap<>();

            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("[\\s\\p{Punct}]+");
                for (String word : words) {
                    String lowercaseWord = word.toLowerCase();
                    wordFrequency.put(lowercaseWord, wordFrequency.getOrDefault(lowercaseWord, 0) + 1);
                }
            }

            for (Map.Entry<String, Integer> entry : wordFrequency.entrySet()) {
                String word = entry.getKey();
                int frequency = entry.getValue();
                System.out.println(word + "=" + frequency);
            }
        } catch (IOException e) {
            System.err.println("파일을 읽어오는 동안 오류가 발생했습니다: " + e.getMessage());
        }
    }
}