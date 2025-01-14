class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;

        vector<int> ans(A.size(), 0);

        int totalCommon= 0;

        for(int i=0; i<A.size(); i++){
            mp[A[i]]++;
            if(mp[A[i]]==2)totalCommon++;
            
            mp[B[i]]++;
            if(mp[B[i]]==2)totalCommon++;

            
            
            
            ans[i]= totalCommon;
        }
        return ans;
    }
};