class Solution {
public:
    int fib(int n) {
        int prev = 0;
        int curnt = 1;
        if(n == 0) return 0;
        for(int i=0; i<n-1; i++){
            int sum = prev+curnt;
            prev = curnt;
            curnt = sum;
        }
        return curnt;
    }
};