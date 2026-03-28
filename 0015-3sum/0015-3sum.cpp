class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> final;
       
        int left = 0 , right = 0 ;
        sort(nums.begin(),nums.end()); // sort
        for(int i = 0 ; i < n-2 ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue; // debug
            }
            
            left = i+1;
            right = n-1;
            int sum = -1 * nums[i];
            
            while(left<right){
                if(nums[left]+nums[right]== sum){
                   final.push_back({nums[i],nums[left],nums[right]});
                
                    left++;
                    right--;
                    while(left<right &&nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left < right && nums[right]==nums[right+1]){
                        right--;
                    }
                }
                else if (nums[left]+nums[right] < sum){
                    left++;
                }
                else
                    right--;
            }
           
        }
        return final;
    }
};