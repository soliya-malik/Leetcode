1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int n =  nums.size();
5        int bestEnd = nums[0];
6        int sum = nums[0];
7        
8
9        if(n==1){
10            return nums[0];
11        }
12
13        for(int i = 1 ; i < n ;i++){
14            int v1 = bestEnd + nums[i];
15            int v2 = nums[i];
16            bestEnd = max(v1,v2);
17            sum = max(sum,bestEnd);
18        }
19        return sum;
20    }
21};