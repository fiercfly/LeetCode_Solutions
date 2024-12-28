class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps= 0;
        int currEnd= 0;
        int maxDis= 0;

        for(int i=0; i<nums.size()-1; i++){
            maxDis= max(maxDis, i+ nums[i]);
            if(i== currEnd){
                currEnd= maxDis;
                ++jumps;
            }
        }
        return jumps;
    }
};