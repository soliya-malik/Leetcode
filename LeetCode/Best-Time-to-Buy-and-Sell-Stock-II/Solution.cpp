1class Solution {
2public:
3
4    int maxProfit(vector<int>& prices) {
5        int n = prices.size();
6        int k = 2;
7
8        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
9
10        int gain = fun(prices, n, 0, k, dp);
11
12        return gain;
13    }
14
15    int fun(vector<int>& prices, int n, int i, int k,
16            vector<vector<int>>& dp) {
17
18        // No days left
19        if (i == n)
20            return 0;
21
22        // No action left
23        if (k == 0)
24            return 0;
25
26        if (dp[i][k] != -1)
27            return dp[i][k];
28
29        if (k == 2) {
30            // Buy
31            int c1 = fun(prices, n, i + 1, k - 1, dp)
32                     - prices[i];
33
34            // Don't buy
35            int c2 = fun(prices, n, i + 1, k, dp);
36
37            return dp[i][k] = max(c1, c2);
38        }
39
40        else if (k == 1) {
41            // Sell
42            int c1 = fun(prices, n, i + 1, k +1, dp)
43                     + prices[i];
44
45            // Don't sell
46            int c2 = fun(prices, n, i + 1, k, dp);
47
48            return dp[i][k] = max(c1, c2);
49        }
50
51        return 0;
52    }
53};