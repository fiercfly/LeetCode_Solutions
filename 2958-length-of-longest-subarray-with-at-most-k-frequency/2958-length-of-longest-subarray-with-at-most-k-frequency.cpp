class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_map<int, int> mp;
        int l=0;
        int r= 0;
        int flag= 0;
        int cnt=0;
        int n= nums.size();
        while(r<n){
            mp[nums[r++]]++;
            if(mp[nums[r-1]] >k)flag= 1;
            while(flag && l<r){
                mp[nums[l++]]--;
                cnt= max(cnt, r-l);
                if(mp[nums[r-1]]==k){
                    flag = 0;
                }
            }
        }
        cnt= max(cnt, r-l);
        return cnt;
    }
};