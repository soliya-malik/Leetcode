1class Solution {
2public:
3    int x[4] = {1,-1,0,0};
4    int y[4] = {0,0,1,-1};
5    bool isvalid(int i , int j ,int n , int m ){
6        if( i<0 || i>= n || j <0 || j >= m ){
7            return false;
8        }
9        return true;
10    }
11    int swimInWater(vector<vector<int>>& grid) {
12        int n = grid.size();
13        int m = grid[0].size();
14
15        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
16
17        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
18        pq.push({grid[0][0],{0,0}});
19        res[0][0] = grid[0][0];
20
21        while(!pq.empty()){
22            pair<int,pair<int,int>> p = pq.top();
23            pq.pop();
24            int money = p.first;
25            int row = p.second.first;
26            int col = p.second.second;
27            if(money > res[row][col]) continue;
28
29            for(int k = 0 ; k < 4 ;k++){
30                int r = row +x[k];
31                int c = col + y[k];
32                if(!isvalid(r,c,n,m)) continue;
33                int new_money = max(money,grid[r][c]);
34
35                if(new_money < res[r][c]){
36                    res[r][c]= new_money;
37                    pq.push({new_money,{r,c}});
38                }
39            }
40        }
41        return res[n-1][m-1];
42    }
43};