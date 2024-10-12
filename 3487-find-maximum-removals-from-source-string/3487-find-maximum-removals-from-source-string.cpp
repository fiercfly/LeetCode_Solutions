class Solution {
public:
    int maxRemovals(string a, string b, vector<int>& c) {
        vector<bool> pr(a.length(), false);
        int x= a.length();
        int y= b.length();
        vector<int> dp(y+1, INT_MAX);
        dp[0]= 0;
        for(int idx: c){
            pr[idx]= true;
        }
        for(int i=0; i<x; i++){
            for(int j=y; j>0; j--){
                if(a[i]==b[j-1] && dp[j-1] !=INT_MAX){
                    int tempo;
                    if(pr[i]== true){
                        tempo= 1;
                    }
                    else{
                        tempo= 0;
                    }
                    dp[j]= min(dp[j], dp[j-1] +tempo);
                }
            }
        }
        return c.size()-(dp[y]==INT_MAX?0:dp[y]);
    }
};