class Solution {
public:
    static int waysToSplitArray(vector<int>& nums) {
        const int n=nums.size();
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        long long acc=0;
        int cnt= 0LL;
        for(int i=0; i<n-1; i++){
            acc += nums[i];
            cnt+= (2*acc >= sum);
        }
        return cnt;
    }
};