1class Solution {
2public:
3    int maxProfit(int k, vector<int>& prices) {
4         int n = prices.size();
5        k = k*2;
6
7        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
8
9        int gain = fun(prices, n, 0, k, dp);
10
11        return gain;
12    }
13     int fun(vector<int>& prices, int n, int i, int k,
14            vector<vector<int>>& dp) {
15
16        // No days left
17        if (i == n)
18            return 0;
19
20        // No action left
21        if (k == 0)
22            return 0;
23
24        if (dp[i][k] != -1)
25            return dp[i][k];
26
27        if (k %2==0) {
28            // Buy
29            int c1 = fun(prices, n, i + 1, k - 1, dp)
30                     - prices[i];
31
32            // Don't buy
33            int c2 = fun(prices, n, i + 1, k, dp);
34
35            return dp[i][k] = max(c1, c2);
36        }
37
38        else  {
39            // Sell
40            int c1 = fun(prices, n, i + 1, k-1, dp)
41                     + prices[i];
42
43            // Don't sell
44            int c2 = fun(prices, n, i + 1, k, dp);
45
46            return dp[i][k] = max(c1, c2);
47        }
48
49        return 0;
50    }
51};