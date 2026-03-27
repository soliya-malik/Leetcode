class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int size = nums.size();
       vector<int> neg ;
       vector<int> pos;
       vector<int> res;
       
        //1. seperating neg and pos
        for(int i = 0 ; i < size;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        //2. if no neg exists
        if(neg.size()==0){
            for(int i = 0 ; i < size;i++){
                int k  = nums[i]* nums[i];
                res.push_back(k);
            }
            return res;
        }
        //3. if no pos neg
        if (pos.size()==0){
            for(int i = 0 ; i < size;i++){
                int k  = nums[i]* nums[i];
                res.push_back(k);
            }
            reverse(res.begin(),res.end());
            return res;
        }
        //3. Both exists
        int n = neg.size();
        int m = pos.size();
        int i = 0 ,j=0;
         // 4. working on neg[]
            for(int i = 0 ; i < n;i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            // 5. Working on pos[]
            for(int i = 0 ; i <m;i++){
                pos[i]=pos[i]*pos[i];
            }
            // 6 merging two array
            while(i<n && j < m ){
                if(neg[i]<pos[j]){
                    res.push_back(neg[i]);
                    i++;
                }else{
                    res.push_back(pos[j]);
                    j++;
                }
            }
            while(i<n){
                res.push_back(neg[i]);
                i++;
            }
            while(j<m){
                res.push_back(pos[j]);
                j++;
            }
        return res;
    }
};