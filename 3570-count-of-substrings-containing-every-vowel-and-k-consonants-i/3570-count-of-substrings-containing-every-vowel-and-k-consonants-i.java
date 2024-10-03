import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countOfSubstrings(String w, int k) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        int ans = 0;
        int n = w.length();

        for (int i = 0; i < n; i++) {
            Set<Character> f = new HashSet<>();
            int vowelCount = 0;

            for (int j = i; j < n; j++) {
                if (vowels.contains(w.charAt(j))) {
                    f.add(w.charAt(j));
                    vowelCount++;
                }
                int nonVowelCount = (j - i + 1) - vowelCount;

                if (nonVowelCount > k) {
                    break;
                }
                if (f.size() == 5 && nonVowelCount == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
