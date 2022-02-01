class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int max_val = max({a, b, c});
        int sum_up = a+b+c;
        int small_two_sum = sum_up-max_val;
        if(max_val >= small_two_sum) return small_two_sum;
        else return (sum_up)/2;
    }
};