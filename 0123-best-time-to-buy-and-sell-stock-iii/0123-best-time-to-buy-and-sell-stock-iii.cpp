class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 4;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        int gain = fun(prices, n, 0, k, dp);

        return gain;
    }

    int fun(vector<int>& prices, int n, int i, int k,
            vector<vector<int>>& dp) {

        // No days left
        if (i == n)
            return 0;

        // No action left
        if (k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k %2==0) {
            // Buy
            int c1 = fun(prices, n, i + 1, k - 1, dp)
                     - prices[i];

            // Don't buy
            int c2 = fun(prices, n, i + 1, k, dp);

            return dp[i][k] = max(c1, c2);
        }

        else  {
            // Sell
            int c1 = fun(prices, n, i + 1, k-1, dp)
                     + prices[i];

            // Don't sell
            int c2 = fun(prices, n, i + 1, k, dp);

            return dp[i][k] = max(c1, c2);
        }

        return 0;
    }
};