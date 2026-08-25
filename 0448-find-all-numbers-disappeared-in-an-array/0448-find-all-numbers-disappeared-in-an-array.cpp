class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> freq(nums.size(), 0);
        vector<int> ans;

        for(int i: nums){
            freq[i-1]++;
        }

        for(int i=0; i<nums.size(); i++){
            if(freq[i] == 0){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};