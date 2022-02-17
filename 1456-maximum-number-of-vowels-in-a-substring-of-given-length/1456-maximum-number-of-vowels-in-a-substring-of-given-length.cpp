class Solution {
public:
    int maxVowels(string s, int k) {
        map<char, int>mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        int ans = 0;
        int tem_count = 0;
        int n = s.size();
        int i = 0, j = 0;
        for(; j<n; j++){
            if(mp[s[j]]){
                tem_count++;
            }
            if(j-i+1 == k){
                ans = max(ans, tem_count);
                if(mp[s[i]]){
                    tem_count--;
                }
                i++;
            }
        }
        return ans;
    }
};