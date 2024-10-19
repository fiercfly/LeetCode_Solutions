
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int ans= 0;
        int sum= 0;
        int n= nums.size();
        int left= 0;
        for(int i=0; i<k; i++){
            sum+= nums[i];
        }
        ans= max(ans, sum);
        for(int i=0; i<k; i++){
            sum+= nums[n-i-1];
            sum-= nums[k-i-1];
            ans=max(ans, sum);
        }
        return ans;
    }
};