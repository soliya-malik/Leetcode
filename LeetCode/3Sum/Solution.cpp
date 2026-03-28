1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<int>> final;
6       
7        int left = 0 , right = 0 ;
8        sort(nums.begin(),nums.end()); // sort
9        for(int i = 0 ; i < n-2 ; i++){
10            if(i>0 && nums[i]==nums[i-1]){
11                continue; // debug
12            }
13            
14            left = i+1;
15            right = n-1;
16            int sum = -1 * nums[i];
17            
18            while(left<right){
19                if(nums[left]+nums[right]== sum){
20                   final.push_back({nums[i],nums[left],nums[right]});
21                
22                    left++;
23                    right--;
24                    while(left<right &&nums[left]==nums[left-1]){
25                        left++;
26                    }
27                    while(left < right && nums[right]==nums[right+1]){
28                        right--;
29                    }
30                }
31                else if (nums[left]+nums[right] < sum){
32                    left++;
33                }
34                else
35                    right--;
36            }
37           
38        }
39        return final;
40    }
41};