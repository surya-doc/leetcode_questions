class Solution {
public:
    // int n, int i, char c, vector<vector<int>> &dp, unordered_map<char, int> &mp
    int MOD=1e9+7;
    long long int getCount(int n, int i, char c, vector<vector<int>> &dp, unordered_map<char, int> &mp){
        if(i == n){
            return 1;
        }
        long long temp = 0;
        if(dp[mp[c]][i] != -1){
            return dp[mp[c]][i]%MOD;
        }
        switch(c){
            case 'a':
                temp = getCount(n, i+1, 'e', dp, mp);
                break;
            case 'e':
                temp = getCount(n, i+1,'a', dp, mp)+getCount(n, i+1,'i', dp, mp);
                break;
            case 'i':
                temp = getCount(n, i+1, 'a', dp, mp)+getCount(n, i+1, 'e', dp, mp)+getCount(n, i+1, 'o', dp, mp)+getCount(n, i+1, 'u', dp, mp);
                break;
            case 'o':
                temp = getCount(n, i+1, 'i', dp, mp)+getCount(n, i+1, 'u', dp, mp);
                break;
            case 'u':
                temp = getCount(n, i+1, 'a', dp, mp);
                break;
        }
        return dp[mp[c]][i] = temp%MOD;
    }
    
    int countVowelPermutation(int n) {
        char c[5] = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;
        
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
        long long ans = 0;
        for(int i=0; i<5; i++){
            ans += getCount(n, 1, c[i], dp, mp);
        }
        return ans%MOD;
    }
};