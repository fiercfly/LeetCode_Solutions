class Solution {
public:
    void generator(int k, int sum, vector<int>& nums, vector<vector<int>>& ans, vector<int>temp, int sm) {
        if(sm == sum){
            ans.push_back(temp);
            return;
        }
        if(k == nums.size() || sm > sum){
            return;
        }

        for(int i=k; i<nums.size(); i++){
            if(i-1>=k && nums[i]== nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            generator(i+1, sum, nums, ans,temp, sm+nums[i]);
            temp.pop_back();
        }
        
        //Second way to recurse
        // Include nums[k] in the current combination

        // temp.push_back(nums[k]);
        // generator(k + 1, sum, nums, ans, temp, sm + nums[k]);
        
        // // Exclude nums[k] and skip all duplicates of nums[k]
        
        // temp.pop_back();
        // while(k + 1 < nums.size() && nums[k+1]== nums[k]){
        //     k++;
        // }
        // generator(k + 1, sum, nums, ans, temp, sm);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        generator(0, target, candidates, ans, {}, 0);
        return ans;
    }
};
