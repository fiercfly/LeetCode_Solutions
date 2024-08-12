class Solution {
public:
    void generator(vector<vector<int>> &ans, int i, vector<int> nums, vector<int> &temp){
        ans.push_back(temp);
        for(int k=i; k<nums.size(); k++){
            temp.push_back(nums[k]);
            generator(ans, k+1,nums, temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generator(ans, 0, nums, temp);

        return ans;
    }
};