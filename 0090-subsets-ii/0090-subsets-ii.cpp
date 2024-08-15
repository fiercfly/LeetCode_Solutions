class Solution {
public:
    void generate(vector<vector<int>> &ans, vector<int> nums,int i, vector<int> temp){
        if(i>= nums.size()){
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        for(int k=i; k<nums.size(); k++){
            if(k>i && nums[k]==nums[k-1])continue;
            temp.push_back(nums[k]);
            generate(ans, nums,k+1, temp);
            temp.pop_back();
        }
        

        // //Seocnd way to recurse
        // temp.push_back(nums[i]);
        // generate(ans, nums, i+1,temp);
        // temp.pop_back();
        // while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
        //     i++;
        // }
        // generate(ans, nums, i+1, temp);

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        generate(ans, nums, 0, {});
        return ans;
    }
};