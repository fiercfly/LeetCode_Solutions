class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int , int> freq;
        for(int damage: power){
            freq[damage]++;
        }
        vector<long long> ud;
        for(auto i: freq){
            ud.push_back(i.first);
        }
        sort(ud.begin(), ud.end());
        int n= ud.size();
        if(n==0)return 0;
        
        vector<long long> dp(n);
        dp[0]= ud[0]*freq[ud[0]];
        for(int i=1;i<n;i++){
            long long curr= ud[i]*freq[ud[i]];
            dp[i]= curr;
            int j= i-1;
            while(j>= 0 && ud[i]-ud[j]<= 2){
                j--;
            }
            if(j>= 0){
                dp[i]+= dp[j];
            }
            dp[i]= max(dp[i], dp[i-1]);
        }
        return dp[n-1];
    }
};