class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        int totalDistinct= 0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            if(mp.find(it) == mp.end()){
                totalDistinct++;
            }
            mp[it]++;
        }

        // cout<<totalDistinct;

        //Sliding window
        // int i=0;
        // int j= 1;
        // unordered_map<int, int> tep;
        // int dis=0;
        // while(i<j && j<nums.size()){
            
        //     if(mp.find(tep[j]) == mp.end()){
        //         dis++;
        //     }

        //     tep[nums[j]]++;

        //     if(dis == totalDistinct){
        //         ans++;
        //     }

        //     j++;

        // }

        for(int i=0; i<nums.size(); i++){
            unordered_map<int,int> temp;
            int dis= 0;
            for(int j=i; j<nums.size(); j++){
                if(temp.find(nums[j]) == mp.end()){
                    dis++;
                }
                temp[nums[j]]++;
                if(dis == totalDistinct){
                    ans++;
                }
            }
        }

        return ans;
    }
};