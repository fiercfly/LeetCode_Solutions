class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return distincts(nums, k)- distincts(nums, k-1);
    }

    int distincts(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int left= 0;
        int right= 0;
        int ans= 0;
        while(right< nums.size()){
            // agr distinct milta h toh..
            if(mp[nums[right]] == 0){
                k--;
            }

            mp[nums[right]]++;
            right++;

            while(k<0){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    k++;
                }
                left++;
            }

            ans+= right- left;
            

        }
        return ans;
    }
};