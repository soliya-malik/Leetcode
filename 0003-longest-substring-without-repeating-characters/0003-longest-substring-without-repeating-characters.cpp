class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0){
            return 0 ;
        }
        int low = 0 , high = 0 ;
        unordered_map<char,int> f;

        int res = INT_MIN;
        for(int high = 0 ; high < n ; high++){
            f[s[high]]++;
            int k = high - low +1 ;
            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                k = high -low+1;
            }
            res = max(res,k);
        }
        return (res==INT_MIN) ? -1 : res;
    }
};