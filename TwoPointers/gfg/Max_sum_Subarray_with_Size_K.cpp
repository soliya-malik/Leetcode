class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0 ;
        int high = k-1;
        int sum = 0 ;
        int res = INT_MIN;
        
        for(int i = low ; i <= high ;i++){
            sum += arr[i]; 
        }
        
        while(high < n){
            res = max(res,sum);
            low++;
            high++;
            
            if(high==n){
                break;
            }
            
            sum -= arr[low-1];
            sum += arr[high];
        }
        return res;
    }
};