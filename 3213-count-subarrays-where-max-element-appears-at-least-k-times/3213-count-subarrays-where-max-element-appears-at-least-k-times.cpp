class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi= *max_element(nums.begin(), nums.end());

        int left= 0;
        int right= 0;
        long long cnt= 0;
        long long ans= 0;

        while(right< nums.size()){
            if(nums[right] == maxi)cnt++;
            while(cnt>=k){
                if(nums[left] == maxi){
                    cnt--;
                }
                left++;
                ans+= nums.size()- right;
            }
            right++;
        }
        return ans;
    }
};


