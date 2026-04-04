1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int n = nums.size();
5        int low = 0 , high = 0 ;
6        int res = INT_MAX ; 
7        int sum = 0 ;
8         
9
10        
11        for(high = 0 ; high < n ; high++){
12            sum += nums[high];
13
14            while(sum >= target){
15                int len = high - low + 1;
16                res = min(res,len);
17                sum -= nums[low];
18                low++;
19            }
20        }
21
22        
23       return (res == INT_MAX) ? 0 : res;
24    }
25};