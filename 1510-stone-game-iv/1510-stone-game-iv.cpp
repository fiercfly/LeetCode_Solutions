class Solution {
public:
    bool winnerSquareGame(int n) {
        // Intuition: bottom-up fill, dp[i] true if some square move leads to a losing state for the opponent
        std::vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};