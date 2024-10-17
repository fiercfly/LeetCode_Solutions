class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left= 0;
        int left2= 0;
        int right= 0;
        int ans = 0;
        int sum1= 0;
        int sum2= 0;
        while(right< nums.size()){
            sum1+= nums[right];
            sum2+= nums[right];

            // narrow down first window till sum1> goal
            while(left<= right && sum1 > goal){
                sum1-= nums[left];
                left++;
            }

            //narrow down second windpw till sum2>= goal
            while(left2<= right && sum2 >= goal){
                sum2-= nums[left2];
                left2++;
            }

            ans+= left2- left;
            
            right++;
        }
        return ans;

    }
};