class Solution {
public:
    void rec(vector<int> &nums, vector<vector<int>> &ans, int ind){
        if(ind >= nums.size()){
            ans.push_back(nums);
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            rec(nums,ans, ind+1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(nums, ans, 0);
        return ans;
        
    }
};

// class Solution {
// public:
//     void rec(vector<vector<int>> &ans, vector<int> &temp, vector<int> &freq, vector<int> &nums ){
//         if(temp.size() == nums.size()){
//             ans.push_back(temp);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++){
//             if(!freq[i]){
//                 temp.push_back(nums[i]);
//                 freq[i]= 1;
//                 rec(ans, temp, freq, nums);
//                 freq[i]= 0;
//                 temp.pop_back();
//             }
//         }

//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> freq(nums.size(), 0);
//         vector<int> temp;

//         rec(ans, temp,freq, nums);

//         return ans;
//     }
// };