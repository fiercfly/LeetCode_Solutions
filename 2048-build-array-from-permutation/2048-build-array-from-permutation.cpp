class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // unordered_map<int, int> mp;
        vector<int> ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
            ans[i]= nums[nums[i]];
        }
        return ans;
    }
};