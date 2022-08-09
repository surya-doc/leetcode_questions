class Solution {
public:
    long moud = pow(10, 9) + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, long> mp;
        long ans = 0;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = 1;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j] == 0){
                    // dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
                    mp[arr[i]] = (mp[arr[i]] + mp[arr[j]]*mp[arr[i]/arr[j]])%moud;
                }
            }
            ans = (ans+mp[arr[i]])%moud;
        }
    return ans;
    }
};