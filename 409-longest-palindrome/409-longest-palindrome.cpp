class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char, int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2 != 0 && !odd){
                ans += it.second;
                odd++;
            }
            else{
                ans += (it.second%2 == 0) ? it.second : it.second-1;
            }
        }
        return ans;
    }
};