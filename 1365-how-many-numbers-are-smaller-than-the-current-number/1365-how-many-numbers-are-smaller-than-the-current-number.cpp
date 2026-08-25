class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp= nums;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int totalSmall= 0;
        // int cur= 0;
        for(int i: nums){
            if(mp.find(i) == mp.end()){
                mp[i]= totalSmall;
            }
            totalSmall++;
        }

        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++){
            ans[i]= mp[temp[i]];
        }

        return ans;
    }
};