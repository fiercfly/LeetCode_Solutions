class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0;
        long long equals= 0;
        unordered_map<int, long long> mp;
        mp[0]= 1; //Zero index is 1

        for(int i: nums){
            if(i%modulo == k)equals++;

            int rem= equals%modulo; //We have rem more..

            int need= (rem - k + modulo)%modulo; // We need this much more

            count+= mp[need];

            mp[rem]++;
        }
        return count;
    }
};
