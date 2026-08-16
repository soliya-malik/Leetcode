1class Solution {
2public:
3    int longestCommonSubsequence(string text1, string text2) {
4       int n = text1.size();
5       int m = text2.size();
6
7       vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
8
9       //nth row 0 and m col =0
10       for(int i = 0 ; i <= n ;i++){
11         dp[i][m]=0;
12       } 
13       for(int i = 0 ; i<= m ;i++){
14        dp[n][i]=0;
15       }
16       for(int i = n-1;i>=0;i--){
17        for(int j = m-1;j>=0;j--){
18            if(text1[i]==text2[j]){
19                dp[i][j]=1+dp[i+1][j+1];
20            }
21            else{
22                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
23            }
24        }
25       }
26       return dp[0][0];
27    }
28};