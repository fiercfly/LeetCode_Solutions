class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int n= prices.size();
    //     vector<vector<int>> dp(n+2, vector<int>(2, 0));

    //     for(int i=n-1; i>=0; i--){
    //         for(int buy= 0; buy<= 1; buy++){
    //             if(buy == 0){
    //                 dp[i][buy]= max(dp[i+1][buy], -prices[i] + dp[i+1][1]);
    //             }
    //             if(buy == 1){
    //                 dp[i][buy]= max(dp[i+1][buy], prices[i]+ dp[i+2][0]);
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }

    int fuc(vector<int> prices, int ind, int buy, vector<vector<int>> &dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][ buy];

        if(buy == 0){
            dp[ind][ buy]= max(fuc(prices, ind+1, buy, dp), -prices[ind]+ fuc(prices, ind+1, 1, dp));
        }
        if(buy == 1){
            dp[ind][buy]= max(fuc(prices, ind+1, buy, dp), prices[ind]+ fuc(prices,ind+2, 0, dp));
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int> prices){
        int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, -1));
        return fuc(prices, 0, 0, dp);
    }
};