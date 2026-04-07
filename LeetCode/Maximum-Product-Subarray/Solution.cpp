1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size();
5        int bestMin = nums[0];
6        int bestMax = nums[0];
7        int product = nums[0] ;
8
9        if(n==1){
10            return nums[0];
11        }
12
13        for(int i = 1 ; i < n ;i++){
14            int v1 = bestMin * nums[i];
15            int v2 = nums[i];
16            int v3 = bestMax * nums[i];
17
18            bestMin = min(v1,min(v2,v3));
19            bestMax = max(v1,max(v2,v3));
20
21            product = max(product,max(bestMin,bestMax));
22        }
23        return product;
24    }
25};