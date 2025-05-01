class Solution {
public:

    //Recursion**********************************************
    // int helper(vector<int> &nums, int &target, int ind, int sum){
    //     if(ind == nums.size() && sum==target){
    //         return 1;
    //     }
    //     if(ind == nums.size()){
    //         return 0;
    //     }

    //     int add= helper(nums, target, ind+1, sum+ nums[ind]);
    //     int min= helper(nums, target, ind+1, sum- nums[ind]);

    //     return add+min;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return helper(nums,target, 0, 0);
    // }

    //DP*****************************
    int findTargetSumWays(vector<int> nums, int target){
        int total=0;
        for(int i: nums){
            total+= i;
        }

        int sum= target+ total;
        if(sum <0 || sum%2 == 1){
            return 0;
        }
        sum= sum/2;

        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0]= 1;

        for(int i=1; i<= n; i++){
            for(int j=0; j<= sum; j++){
                //Sum j using i elements
                dp[i][j]= dp[i-1][j];
                if(j>= nums[i-1]){
                    dp[i][j]+= dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];


    }
};