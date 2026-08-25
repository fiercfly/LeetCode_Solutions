class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int index= 0;
        int small= 1;

        while(true){
            if(index<nums.size()-1 && small > nums[index]){
                index++;
                continue;
            }

            if(small%k==0 && small != nums[index]){
                return small;
            }
            else{
                small++;
            }
        }
        return -1;
    }
};

/*
nums
k
to find: smallest pos multiple of k which is not present in nums
*/