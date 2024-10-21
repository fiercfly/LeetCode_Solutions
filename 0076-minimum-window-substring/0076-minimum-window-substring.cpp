class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        // Fill the map with frequency of characters in `t`.
        for (char c : t) {
            map[c]++;
        }

        // Sliding window approach.
        while (end < s.length()) {
            // Decrement the character count from the map.
            if (map[s[end]] > 0) {
                count--;
            }
            map[s[end]]--;
            end++;

            // When all characters from `t` are found.
            while (count == 0) {
                // Update the minimum window.
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                // Restore the character count for the start of the window.
                map[s[start]]++;
                
                // If restoring this character brings the map value to positive,
                // it means we need this character again.
                if (map[s[start]] > 0) {
                    count++;
                }

                // Move the start pointer forward.
                start++;
            }
        }

        // If no valid window found, return empty string.
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
