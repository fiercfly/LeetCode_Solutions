class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charArr(500, 0);
        int right= 0;
        int left= 0;
        int maxi= 0;
        if(s.length()==0){
            return 0;
        }

        while(right< s.length()){
            if(charArr[s[right]- ' '] > 0){
                while(s[left] != s[right]){
                    charArr[s[left]- ' ']--;
                    left++;
                }
                charArr[s[left]- ' ']--;
                left++;
            }
            charArr[s[right]- ' ']++;
            maxi= max(right-left+1, maxi);
            right++;
        }
        return maxi;
    }
};