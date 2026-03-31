1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int n = nums.size();
5        int low = 0 , high = 0 ;
6        int res = INT_MAX ; 
7        int sum = 0 ;
8         
9
10        while(high<n){
11            sum += nums[high];
12            while(sum >= target){
13                int len = high -low+1;
14                res = min (res,len);
15                sum -= nums[low];
16                low++;
17            }
18            high++;
19           
20        }
21       return (res == INT_MAX) ? 0 : res;
22    }
23};