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

    //Space optimised:

    // vector<int> buildArray(vector<int> nums){
    //     for(int i=0; i<nums.size(); i++)
    //         nums[i]= (nums[i]+ 1024*((nums[nums[i]])%1024));

    //     for(int i=0; i<nums.size(); i++)
    //         nums[i]= nums[i]/1024;

    //     return nums;
    // }


};