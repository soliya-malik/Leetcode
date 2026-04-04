class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0 , high = 0 ;
        int res = INT_MIN;
        int n = nums.size();
        int freq[2] = {0};

        for(high = 0 ; high < n ;high++){
           freq[nums[high]]++;

           while(freq[0]>k){
             freq[nums[low]]--;
             low++;
           }

           int len = high -low +1;
           res = max(res,len);
        }
        return (res==INT_MIN) ? 0 : res;
    }
};