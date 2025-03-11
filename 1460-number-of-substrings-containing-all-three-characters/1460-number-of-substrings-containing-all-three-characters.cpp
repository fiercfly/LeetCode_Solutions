class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int left= 0;
        int right = 0;
        int ans= 0;
        while(right< s.length()){
            mp[s[right]]++;
            right++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>= 1){
                ans+= s.length()-right+1;
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};

//a b c a b c
//|     | 
//0 1 2 3 4 5
//6- 3+1= 4