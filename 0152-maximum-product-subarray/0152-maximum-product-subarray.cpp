class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int bestMin = nums[0];
        int bestMax = nums[0];
        int product = nums[0] ;

        if(n==1){
            return nums[0];
        }

        for(int i = 1 ; i < n ;i++){
            int v1 = bestMin * nums[i];
            int v2 = nums[i];
            int v3 = bestMax * nums[i];

            bestMin = min(v1,min(v2,v3));
            bestMax = max(v1,max(v2,v3));

            product = max(product,max(bestMin,bestMax));
        }
        return product;
    }
};