1class Solution {
2public:
3    int hammingWeight(int n) {
4        int res = 0 ;
5        while(n>0){
6            res++;
7            n = n &(n-1);
8        }
9        return res;
10    }
11};