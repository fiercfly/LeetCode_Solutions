
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int left= 0;
        int right= 0;
        int n= s.size();
        int maxi= 0;
        int maxl= 0;

        while(right < n){
            mp[s[right]]++;
            maxi= max(maxi, mp[s[right]]);

            if((right- left +1)- maxi > k){
                mp[s[left]]--;
                left++;
            }

            maxl = max(maxl, right- left+1);
            right++;
        }

        return maxl;
    }
};