class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int no_delete = arr[0] ;
        int one_delete = INT_MIN ;
        int res = INT_MIN ;

        if(n==1){
            return arr[0];
        }

        for(int i = 1 ; i < n ;i++){
            int prev_no_deletion = no_delete;
            int prev_one_deletion = one_delete;

            no_delete = max(prev_no_deletion + arr[i],arr[i]);
            int v1 = 0 ;
            if(one_delete==INT_MIN){
                v1 = arr[i];
            }else{
                v1 = prev_one_deletion + arr[i];
            }

            one_delete = max(v1,prev_no_deletion);
            res= max(res,max(no_delete,one_delete));
        }
        return res;

    }
};