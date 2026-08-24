1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        stack<int> st;
6        vector<int> res(n);
7        st.push(n-1);
8        for(int i = n-2;i>=0;i--){
9            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
10                st.pop();
11            }
12            if(st.empty()) res[i]=0;
13            else{
14                res[i]=st.top() - i;
15            }
16            st.push(i);
17        }
18        return res;
19    }
20};