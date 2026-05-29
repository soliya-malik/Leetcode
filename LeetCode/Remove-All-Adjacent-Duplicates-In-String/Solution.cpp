1class Solution {
2public:
3    string removeDuplicates(string s) {
4        int n = s.size();
5        stack<char> st ;
6        string res;
7
8        for(int i = 0 ; i < n ; i++){
9            if(st.empty() || st.top() != s[i] ){
10                st.push(s[i]);
11                continue;
12            }
13            if(st.top()==s[i]){
14                st.pop();
15            }
16        }
17        while(!st.empty()){
18            char c = st.top();
19            st.pop();
20            res.push_back(c);
21        }
22        reverse(res.begin(),res.end());
23
24        return res;
25    }
26};