class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        int left = 0 , right = 0 ;
        int max_diff = INT_MAX;
        int res=0;

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            left = i+1;
            right = n-1;

            
            while(left<right){
                int sum  = nums[i]+nums[left]+ nums[right];
                int diff = abs(sum-target);
                    if(diff<max_diff){
                        res = sum;
                        max_diff = diff;
                    }
                if(sum == target){
                    return sum;
                }
               
                else if(sum < target){
                    
                    left++;
                }
                else
                    right--;
            }
        }
        return res;
    }
};