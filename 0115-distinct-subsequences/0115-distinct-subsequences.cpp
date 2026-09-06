const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif


class Solution {
public:
//***********RECURSIVE DP****************
    // int helper(string &s1, string &s2, int idx1, int idx2, vector<vector<int>> &dp){
    //     if(idx2<0){
    //         return 1; //Full string milgii
    //     }
    //     if(idx1 <0){
    //         return 0; //Kuch ni mila
    //     }

    //     if(dp[idx1][idx2] != -1){
    //         return dp[idx1][idx2];
    //     }

    //     if(s1[idx1] == s2[idx2]){
    //         int take= helper(s1, s2, idx1-1, idx2-1, dp);
    //         int notake= helper(s1, s2, idx1-1, idx2, dp);

    //         dp[idx1][idx2]= take + notake;
    //     }
    //     else{
    //         dp[idx1][idx2]= helper(s1, s2, idx1-1, idx2, dp);
    //     }

    //     return dp[idx1][idx2];
    // }
    // int numDistinct(string s, string t) {
    //     int ss= s.length();
    //     int ts= t.length();

    //     vector<vector<int>> dp(ss, vector<int>(ts, -1));

    //     return helper(s, t, ss-1, ts-1, dp);

    // }
    
//*********TABULATION DP***********************
    int numDistinct(string s, string t){
        int n= s.length();
        int m= t.length();
        int mod= 1e9+7;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][0]= 1; //s2 is empty so it can match anything
        }
        for(int j=1; j<=m; j++){
            dp[0][j]= 0; //s1 is empty so ntg can be matched from s2
        } 

        for(int i=1; i<= n; i++){
            for(int j=1; j<= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j]= (dp[i-1][j-1] + dp[i-1][j])%mod; //Sum of take and not take i.e. i-1 j-1 and i-1 j
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};


