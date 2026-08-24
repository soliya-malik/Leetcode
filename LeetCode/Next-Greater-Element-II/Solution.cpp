1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        stack<int> st;
6        vector<int> res(n,-1);
7        
8        for(int i = 2*n-1;i>=0;i--){
9            int index= i%n;
10            while(!st.empty() && st.top() <= nums[index]){
11                st.pop();
12            }
13            if(i<n && !st.empty()) res[index]= st.top();
14           
15            st.push(nums[index]);
16        }
17        return res;
18    }
19};