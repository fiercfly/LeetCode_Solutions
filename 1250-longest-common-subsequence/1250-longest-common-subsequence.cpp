class Solution {
public:
    //Recursion********************************************************************************
    // int helper(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
    //     if(ind1 < 0 || ind2< 0){
    //         return 0;
    //     }
    //     if(dp[ind1][ind2] != -1){
    //         return dp[ind1][ind2];
    //     }

    //     if(s1[ind1] == s2[ind2]){
    //         return dp[ind1][ind2]= 1+ helper(s1, s2, ind1-1, ind2-1, dp);
    //     }
    //     else{
    //         return dp[ind1][ind2]= max(helper(s1,s2, ind1, ind2-1, dp), helper(s1, s2, ind1-1, ind2, dp));
    //     }
    // }


    // int longestCommonSubsequence(string s1, string s2) {
    //     vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    //     return helper(s1, s2, s1.length()-1, s2.length()-1, dp);
    // }

    //Tabulation******************************************************************************
    int longestCommonSubsequence(string s1, string s2){
        int n= s1.length();
        int m= s2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<= n; i++){
            for(int j=1; j<= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }


};