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

//********************************************************

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


//*********************************************************

        // unordered_map<int,int> temp;
        // int left = 0;

        // for(int i=0; i<nums.size(); i++){
        //     temp[nums[i]]++;
        //     while(temp.size() == totalDistinct){
        //         ans+= nums.size()- i;
        //         temp[nums[left]]--;
        //         if(temp[nums[left]] == 0)temp.erase(nums[left]);
        //         left++;
        //     }
        // } 


        return ans;
    }
};