class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end()), mini = *min_element(nums.begin(), nums.end()), remain;
        return __gcd(mini, maxi);
    }
};