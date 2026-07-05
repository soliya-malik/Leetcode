1class Solution {
2public:
3    string reorganizeString(string s) {
4        int n = s.size();
5        unordered_map<char,int>f;
6        for(int i = 0 ; i < n ;i++){
7            f[s[i]]++;
8        }
9        //max heap
10        priority_queue<pair<int,char> > pq;
11        // to iterate over the map use auto for loop
12        for(auto &it:f){
13            pq.push({it.second,it.first});
14        }
15        string res ="";
16        res = fun(pq,res);
17         return res;
18    }
19    private:
20    string fun(priority_queue<pair<int,char> >& pq, string &res ){
21        int seat = 0 ;
22        while(!pq.empty()){
23            pair<int,char> p1 = pq.top();
24            pq.pop();
25            if(res.empty() || res.back() != p1.second){ // we can use res.back() to see the previous element
26                res.push_back(p1.second);
27                seat++;
28                p1.first--;
29                if(p1.first>0){
30                    pq.push(p1);
31                }
32            }
33            else{
34                if(pq.empty()){
35                    return "";
36                }
37                pair<int,char> p2 = pq.top();
38                pq.pop();
39                res.push_back(p2.second);
40                seat++;
41                p2.first--;
42                if(p2.first>0){
43                    pq.push(p2);
44                }
45                pq.push(p1);
46            }
47        }
48        return res;
49    }
50};