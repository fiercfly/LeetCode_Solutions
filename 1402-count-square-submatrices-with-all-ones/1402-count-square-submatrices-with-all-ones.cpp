

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();    
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        
        //sbse pehle first row and col
        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = matrix[i][0];
        //     ans += dp[i][0];
        // }
        // for (int j = 1; j < m; j++) {
        //     dp[0][j] = matrix[0][j];
        //     ans += dp[0][j];  
        // }
        //Now remaining row and cols with DP
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1 && i>0 && j>0) {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                else{
                    dp[i][j] = matrix[i][j];
                }
                
                
                ans += dp[i][j];
            }
        }
        return ans;
    }
};