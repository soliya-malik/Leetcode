class Solution {
private:
    bool  fun(int s_array[256], int t_array[256]){
        for(int i = 0 ; i < 256 ; i++){
            if(s_array[i] < t_array[i]){
                return false;

            }
        }
        return true;
    }  
public:
    string minWindow(string s, string t) {
        int low = 0 , high = 0 ;
        int res = INT_MAX;
        int s_array[256] = {0};
        int t_array[256] ={0};
        int start = -1 ;


        for(int i =0 ; i < t.size() ; i++){
            t_array[t[i]]++;
        }
        int n = s.size();
        int m = t.size();
        if(n<m){
            return "";
        }
        

        for(high = 0 ; high < n ;high++){
            s_array[s[high]]++;

            while(fun(s_array,t_array)){
                int len = high - low +1;
                if(len < res){
                    res = len;
                   start = low;
                }
                s_array[s[low]]--;
                low++;
            }

        }
        return (res==INT_MAX) ? "" : s.substr(start,res);
    }

};