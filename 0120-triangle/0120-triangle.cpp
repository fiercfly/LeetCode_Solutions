class Solution {
public:
//     int minimumTotal(vector<vector<int>>& t) {
//         for(int i=1; i<t.size(); i++){
//             int pCol = t[i-1].size();
//             for(int j= 0; j<t[i].size(); j++){
//                 t[i][j] = min(j-1>=0? t[i-1][j-1]+ t[i][j]: 1e9 , j< pCol? t[i-1][j]+t[i][j] : 1e9);
//             }
//         }

//         int ans=  t[t.size()-1][0];

//         for(int i= 1; i<t[t.size()-1].size(); i++){
//             cout<<t[t.size()-1][i]<<endl;
//             ans= min(ans, t[t.size()-1][i]);
//         }

//         return ans;
//     }


//RECURSIVE DP: down, down right
    int solve(vector<vector<int>> &t, vector<vector<int>> &dp, int row, int col){
        if(row == t.size()-1){
            return t[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int down = t[row][col] + solve(t, dp, row+1 , col);
        int downR = t[row][col] + solve(t, dp, row+1 , col+1);

        dp[row][col] = min(down, downR);

        return dp[row][col];
        
    }

    int minimumTotal(vector<vector<int>> &t){
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), -1));

        return solve(t, dp, 0 , 0);
    }
};

//Directions we can movwe: downwards or downwards+ 1
//No need to create DP array we can do all in the array itself
//For index j: check for i-1, j & i-1,j-1
// Take the minimum and at the end make it as answer..




