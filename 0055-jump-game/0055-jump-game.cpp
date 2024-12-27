class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumpsLeft= 0;
        int des= nums.size()-1;

        for(int i=0;i<nums.size(); i++){
            //start jumping from each index and check if we can reach the des && maxJumpsLeft is >= 0

            //we dont have any jumps left
            if(i>0 && maxJumpsLeft< 0){
                return false;
            }

            maxJumpsLeft= max(maxJumpsLeft, nums[i]);
            if(i+ maxJumpsLeft == des || i==des){
                return true;
            }

            // *Jumps*
            maxJumpsLeft--;
        }
        return false;
    }
};

/*

2 3 1 1 4
we have to reach: 4
st:
0-> 2= max 2 now
1-> 4= max 4 now

*/