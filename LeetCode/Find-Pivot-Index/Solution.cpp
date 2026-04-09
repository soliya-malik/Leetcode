1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int n = nums.size();
5        int left = 0 ;
6        
7        int sum = 0;
8        
9        for(int i = 0 ;i < n ;i++){
10            sum += nums[i];
11        }
12
13        for(int i = 0 ; i < n ; i++){
14            int right=sum-left-nums[i];
15           if(left==right)
16           return i;
17
18
19           left=left+nums[i];
20
21        }
22        return -1;
23    }
24};