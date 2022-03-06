class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>mp;
        int ans = -1;
        for(int i=0; i<s.size(); i++){
            if(!mp[s[i]]){
                mp[s[i]] = i+1;
            }
            else{
                mp[s[i]] = -1;
            }
        }
        for(auto it:mp){
            if(it.second != -1){
                if(ans != -1){
                    ans = min(ans, it.second-1);
                }
                else{
                    ans = it.second-1;
                }
            }
        }
        return ans;
    }
};