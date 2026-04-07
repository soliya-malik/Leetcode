1class Solution {
2public:
3    int maximumSum(vector<int>& arr) {
4        int n = arr.size();
5        int no_delete = arr[0] ;
6        int one_delete = INT_MIN ;
7        int res = INT_MIN ;
8
9        if(n==1){
10            return arr[0];
11        }
12
13        for(int i = 1 ; i < n ;i++){
14            int prev_no_deletion = no_delete;
15            int prev_one_deletion = one_delete;
16
17            no_delete = max(prev_no_deletion + arr[i],arr[i]);
18            int v1 = 0 ;
19            if(one_delete==INT_MIN){
20                v1 = arr[i];
21            }else{
22                v1 = prev_one_deletion + arr[i];
23            }
24
25            one_delete = max(v1,prev_no_deletion);
26            res= max(res,max(no_delete,one_delete));
27        }
28        return res;
29
30    }
31};