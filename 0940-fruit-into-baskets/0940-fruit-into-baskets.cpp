class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> vct;
        int type = 0;
        
        while(right < fruits.size()) {
            if(vct[fruits[right]] == 0 && type == 2) {
                while(type == 2) {
                    int trgt = fruits[left];
                    vct[trgt]--;
                    if(vct[trgt] == 0) {
                        type--;
                    }
                    left++;
                }
            }
            if(vct[fruits[right]] == 0) {
                type++;
            }
            vct[fruits[right]]++;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
