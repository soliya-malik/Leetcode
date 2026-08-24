1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        int n = s.size();
5        string res = "";
6        stack<pair<char,int>> st;
7        for(int i = 0 ; i < n ;i++){
8            char ch = s[i];
9            if(st.empty()){
10                st.push({ch,1});
11                continue;
12            }
13            if(st.top().first != ch){
14                st.push({ch,1});
15                continue;
16            }
17            if(st.top().second  < k-1){
18                pair<char,int> p = st.top();
19                st.pop();
20                char c = p.first;
21                st.push({c,p.second+1});
22                continue;
23            }
24           st.pop();
25        }
26        while(!st.empty()){
27            pair<char,int> p = st.top();
28            st.pop();
29            while(p.second--){
30                res.push_back(p.first);
31            }
32
33        }
34        reverse(res.begin(),res.end());
35        return res;
36    }
37};