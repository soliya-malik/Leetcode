1class Solution {
2private:
3    int fun(int n){
4        int sum = 0 ;
5        while(n>0){
6            int d = n%10;
7            n /= 10;
8            sum = sum + d*d;
9        }
10        return sum;
11    }    
12public:
13    bool isHappy(int n) {
14        int slow = n ;
15        int fast = n ;
16
17        while(fast !=1){
18            slow = fun(slow);
19            fast= fun(fast);
20            fast= fun(fast);
21
22           if(fast == slow && slow !=1){
23            return false;
24           }
25
26        }
27        return true;
28    }
29};