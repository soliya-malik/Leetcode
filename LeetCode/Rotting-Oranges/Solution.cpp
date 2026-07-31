1class Solution {
2public:
3    int x[4] = {-1,1,0,0};
4    int y[4] = {0,0,-1,1};
5    bool isvalid(int i , int j , int n , int m ){
6    if(i <0 || i>=n || j <0 || j>=m){
7        return false;
8    }
9    return true;
10 }
11    int orangesRotting(vector<vector<int>>& grid) {
12        int n = grid.size();
13        int m = grid[0].size();
14        queue<pair<int,int>> q ;
15        int fresh = 0 ;
16        int time = 0;
17        for(int i = 0; i < n ; i++){
18            for(int j = 0 ; j < m ;j++){
19                if(grid[i][j]==2){
20                    q.push({i,j});
21                }
22                else if(grid[i][j]==1){
23                    fresh++;
24                }
25            }
26        }
27        while(!q.empty() && fresh >0){
28            time++;
29            int s = q.size();
30            while(s--){
31                pair<int,int> p = q.front();
32                q.pop();
33                int row = p.first;
34                int col = p.second;
35                for(int k = 0 ; k < 4 ;k++){
36                    int r =row + x[k];
37                    int c = col + y[k];
38                    if(isvalid(r,c,n,m) && grid[r][c]==1){
39                        q.push({r,c});
40                        grid[r][c] = -2;
41                        fresh--;
42                    }
43                }
44            }
45
46        }
47        if(fresh>0) return -1;
48        return time;
49    }
50};