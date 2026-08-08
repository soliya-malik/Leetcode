1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<int> res(n,1e8);
5        res[src]=0;
6        for(int i = 0 ; i <= k ;i++){
7            vector<int> t = res;
8            for(int j = 0 ; j< flights.size();j++){
9                int s = flights[j][0];
10                int d = flights[j][1];
11                int w = flights[j][2];
12
13                if(res[s] != 1e8 && t[d] > res[s]+w){
14                    t[d] = res[s] + w;
15                }
16
17
18            }
19            res = t;
20
21        }
22        return res[dst]==1e8 ? -1: res[dst];
23
24    }
25};