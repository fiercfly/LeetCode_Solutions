class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans= 0;
        int left= 0;
        int right= 0;
        int flip= 0;
        while(right< nums.size()){
            if(nums[right]== 1){
                ans= max(ans, right- left+1);
                right++;
                
            }
            else{
                if(flip<k){
                    flip++;
                    ans= max(ans, right- left+1);
                    right++;
                    
                }
                else{
                    while(nums[left]!= 0){
                        left++;
                    }
                    left++;
                    ans= max(ans, right- left+1);
                    right++;
                }
            }

        }
        return ans;
    }
};