class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // // check from least value to most value possible
        // sort(nums.begin(), nums.end());
        // unordered_map<int, int> mp;
        // int cnt= 0;

        // // try for -k to k for each elt

        // for (int i = 0; i < nums.size(); i++) {

        //     int temp = k;
        //     bool find = false;

        //     while (temp >= 0 && !find) {
        //         if (mp.find(nums[i] - temp) == mp.end()) {
        //             mp[nums[i] - temp]++;
        //             find = true;
        //             cnt++;
        //         }
        //         temp--;
        //     }

        //     temp = 1;

        //     while(temp <= k && !find){
        //         if (mp.find(nums[i] + temp) == mp.end()) {
        //             mp[nums[i] + temp]++;
        //             find = true;
        //             cnt++;
        //         }
        //         temp++;
        //     }
        // }
        // return cnt;


        //sort the array
        sort(nums.begin(), nums.end());

        //pick the minimum element

        int cnt= 0;
        int prev= -1e9;

        for(int i=0; i<nums.size(); i++){
            int pos= max(nums[i]-k, prev+1);
            if(pos <= nums[i]+k){
                prev= pos;
                cnt++;
            }
        }
        return cnt;
    }
};