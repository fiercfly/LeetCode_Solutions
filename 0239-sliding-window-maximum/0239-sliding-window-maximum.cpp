class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        queue<int> q;
        int i=0;
        int mxi= INT_MIN;
        while(i<k){
            q.push(nums[i]);
            mp[nums[i]]++;
            mxi =max(mxi, nums[i]);
            i++;
        }
        ans.push_back(mxi);
        while(i<nums.size()){
            if(q.front() == mxi && mp[mxi]==1){
                q.push(nums[i]);
                mp[nums[i]]++;
                mp[mxi]--;
                q.pop();
                
                mxi= INT_MIN;
                for(int j= i-k+1; j<=i; j++){
                    mxi =max(mxi, nums[j]);
                }
                ans.push_back(mxi);
            }
            else{
                mp[q.front()]--;
                mxi= max(mxi, nums[i]);
                ans.push_back(mxi);
                q.push(nums[i]);
                q.pop();
                mp[nums[i]]++;
            }
            i++;
        }
        return ans;

    }
};