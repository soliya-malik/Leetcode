class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0 ;
        for(int i= 0 ;i < n ;i++){
            total += nums[i];
        }
         if(total % 2==1){
            return 0;
         }
         else{
         return subset(nums,n,total/2) ;
         }
    }
    bool subset(vector<int>& nums,int n , int sum){
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        dp[n][0] =1;

        for(int i = n-1;i>=0;i--){
            for(int j = 0 ; j <= sum;j++){
                if(j < nums[i]){
                    dp[i][j]=dp[i+1][j];
                }
                else{
                    dp[i][j]= dp[i+1][j-nums[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
};