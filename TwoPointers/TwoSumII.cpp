class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int f = 0;
        int r = n-1;
       vector<int> res;
        while(f<r){
            if(numbers[r]+numbers[f]==target){                res.push_back(f+1);
                res.push_back(r+1);
               
                break;
            }
            else if(numbers[r]+numbers[f]>target){
                r--;
            }
            else{
                f++;
            }
            
            }
           return res;  
        }
       
    
};