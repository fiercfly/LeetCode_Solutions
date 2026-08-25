class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ext=0;
        int miss= 0;

        // sort(nums.begin(), nums.end());

        // for(int i=1; i<= nums.size(); i++){
        //     if(nums[i-1] != i){
        //         ext= nums[i-1];
        //         miss= i;
        //     }
        // }

        // 1 xor 2 xor 

        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
            if(mp[i] > 1){
                ext= i;
            }
        }

        for(int i=1; i<=nums.size(); i++){
            if(mp.find(i) == mp.end()){
                miss= i;
                break;
            }
        }

        return {ext, miss};
    }
};

// 2 xor 3