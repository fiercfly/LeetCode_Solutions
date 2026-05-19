class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <long long, long long>mp;
        set<int> st1;
        set<int> st2;
        // for(auto it: nums1){
        //     if(mp[it] >0){
        //         continue;
        //     }
        //     else{
        //         mp[it]++;
        //     } 
        // }
        st1.insert(nums2.begin(), nums2.end());
        st2.insert(nums1.begin(), nums1.end());
        for(auto it: st2){
            mp[it]++;
        }
        for(auto it: st1){
            mp[it]++;
            cout<<mp[it]<<" "<<it<<endl;
            if(mp[it] == 2){
                return it;
                break;
            }
        }
        return -1;
    }
};