1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        int n = stones.size();
5        priority_queue<int>  pq;
6        for(int i = 0 ; i < n; i++){
7            pq.push(stones[i]);
8        }
9        int res =0;
10         res = fun(pq,res);
11        return res;
12    }
13    private:
14    int fun(priority_queue<int>  &pq,int res){
15        while(pq.size() > 1){
16            int x = pq.top(); pq.pop();
17            int y = pq.top(); pq.pop();
18
19            // if(x>=y){
20            //     x -= y;
21            //     y=0;
22            // }
23            // else{
24            //     x = 0 ;
25            //     y -= y-x;
26            // }
27            // if(x>0) pq.push(x);
28            // if(y>0)pq.push(y);
29
30              if(x != y){
31                pq.push(x-y);
32            }
33        }
34        return pq.empty() ? 0 : pq.top();
35        
36    }
37};