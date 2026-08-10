class Solution {
public:
    unordered_map<int,int> d;
    int climbStairs(int n) {
       return fun(0,n);
    }
    int fun(int i ,int n){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(d.find(i) != d.end()){
            return d[i];
        }
        return d[i]=fun(i+1,n)+fun(i+2,n);
    }
};