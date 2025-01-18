import java.util.*;

public class AnagramFinder {
    public static String[] findMaxAnagramGroup(String words) {
        // Split the input string into words
        String[] wordArray = words.split(" ");
        
        // Map to store sorted word as key and list of anagrams as value
        Map<String, List<String>> anagramGroups = new LinkedHashMap<>();
        
        // Group words by sorted characters (anagrams will have the same sorted characters)
        for (String word : wordArray) {
            char[] charArray = word.toCharArray();
            Arrays.sort(charArray);
            String sortedWord = new String(charArray);
            
            anagramGroups.putIfAbsent(sortedWord, new ArrayList<>());
            anagramGroups.get(sortedWord).add(word);
        }
        
        // Find the group with the maximum size and return the first occurring one
        List<String> maxAnagramGroup = new ArrayList<>();
        for (List<String> group : anagramGroups.values()) {
            if (group.size() > maxAnagramGroup.size()) {
                maxAnagramGroup = group;
            }
        }
        
        // Convert the list to an array and return
        return maxAnagramGroup.toArray(new String[0]);
    }
}