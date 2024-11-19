import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class TextSearch {

    public List<String> splitIntoSentences(String text) {
        return Arrays.stream(text.split("\\."))
                .filter(sentence -> !sentence.isEmpty())
                .map(sentence -> sentence + ".")
                .collect(Collectors.toList());
    }

    public Map<String, Set<String>> buildHashTable(List<String> sentences) {
        Map<String, Set<String>> hashTable = new HashMap<>();
        for (String sentence : sentences) {
            String[] words = sentence.split("\\s+");
            for (String word : words) {
                String cleanWord = word.replaceAll("\\p{Punct}", "");
                hashTable.computeIfAbsent(cleanWord, k -> new HashSet<>()).add(sentence);
            }
        }
        return hashTable;
    }

    public Set<String> searchKeyword(Map<String, Set<String>> hashTable, String keyword) {
        return hashTable.getOrDefault(keyword, Collections.emptySet());
    }

    public String loadTextFromFile(String fileName) {
        StringBuilder text = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                text.append(line).append("\n");
            }
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
            return "";
        }
        return text.toString();
    }
}