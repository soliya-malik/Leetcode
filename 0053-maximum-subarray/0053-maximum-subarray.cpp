class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =  nums.size();
        int bestEnd = nums[0];
        int sum = nums[0];
        

        if(n==1){
            return nums[0];
        }

        for(int i = 1 ; i < n ;i++){
            int v1 = bestEnd + nums[i];
            int v2 = nums[i];
            bestEnd = max(v1,v2);
            sum = max(sum,bestEnd);
        }
        return sum;
    }
};