class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int bits= nums.size();
       vector<vector<int>> ans;
    //    int ttl= pow(2,nums);
    unsigned int ttl = pow(2, bits); 
       for(int cnt=0; cnt<ttl; cnt++){
        vector<int> vct;
        for(int i=0; i<bits; i++){
            if(cnt&(1<<i)){
                vct.push_back(nums[i]);
            }
        }
        ans.push_back(vct);
       } 
       return ans;
    }
};