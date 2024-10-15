class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        vector<int>prefixSum(n);
        long long ans=0;

        prefixSum[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+(s[i]-'0');
        }


        for(int i=1;i<n;i++){
            if(prefixSum[i-1]==prefixSum[i]){
                ans+=prefixSum[i];
            }
        }
        
        return ans;
    }
};