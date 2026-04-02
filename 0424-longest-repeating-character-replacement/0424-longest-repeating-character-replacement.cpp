class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0 , high = 0 ;
        int res = INT_MIN;
        int f[256]={-1};
        for(high = 0 ; high < n ;high++)
        {
            f[s[high]]++;
            int len = high-low+1;
            int maxi = find(f);
            int diff = len - maxi;

            while(diff>k){
                f[s[low]]--;
                low++;
                len = high-low+1;
                 maxi = find(f);
                 diff = len - maxi;
            }
            len = high -low +1;
            res = max(res,len);
        }
        return (res==INT_MIN) ? 0 : res;
    }
private :
    int find(int f[256]){
        int maxc=-1;
        for(int i = 0 ; i <256 ;i++){
            maxc = max(maxc,f[i]);
        }
        return maxc;
    }
};