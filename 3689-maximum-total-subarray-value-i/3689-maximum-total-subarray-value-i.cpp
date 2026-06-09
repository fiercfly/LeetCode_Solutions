class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini= nums[0];
        int maxi= nums[0];

        for(auto i: nums){
            mini= min(mini, i);
            maxi= max(maxi, i);
        }

        return (long long)k*(maxi-mini);
    }
};