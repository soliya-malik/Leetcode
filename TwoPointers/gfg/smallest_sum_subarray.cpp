// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int n =  a.size();
        int bestEnd = a[0];
        int sum = a[0];
        

        if(n==1){
            return a[0];
        }

        for(int i = 1 ; i < n ;i++){
            int v1 = bestEnd + a[i];
            int v2 = a[i];
            bestEnd = min(v1,v2);
            sum = min(sum,bestEnd);
        }
        return sum;
    }
};
