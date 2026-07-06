1class Solution {
2public:
3    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
4        int n = profits.size();
5        vector<pair<int,int>> proj;
6
7        for(int i = 0 ; i < n ; i++){
8            proj.push_back({capital[i],profits[i]});
9        }
10        sort(proj.begin(),proj.end());
11        priority_queue<int> pq;
12
13        int idx  = 0 ;
14        while(k--){
15            while(idx<n){
16                if(proj[idx].first > w){
17                    break;
18                }
19                pq.push(proj[idx].second);
20                idx++;
21            }
22            if(pq.empty()){
23                return w;
24            }
25            w += pq.top();
26            pq.pop();
27        }
28        return w ;
29    }
30};