1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n = nums.size();
5        int reach = 0 ;
6        for(int i = 0 ;i <n;i++){
7            if(reach < i){
8                return false;
9            }
10            reach = max(reach,i+nums[i]);
11            if(reach >= n-1){
12                return true;
13            }
14        }
15        return true;
16    }
17};