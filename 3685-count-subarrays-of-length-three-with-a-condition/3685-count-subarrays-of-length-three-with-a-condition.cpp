class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        //Sliding window

        if(nums.size() < 3) return -1;

        int left = 0;
        int right = 2;
        int middle = 1;

        int ans =  0;
        int sum= 0;
        while(right < nums.size()){
            sum= nums[left]+ nums[right];
            
            if(nums[middle] == sum*2) ans++;

            left++;
            right++;
            middle++;


        }

        return ans;

    }
};

//subarray with conditions:

//Subarray of length 3
//Sum of the first and third number = second number/2

