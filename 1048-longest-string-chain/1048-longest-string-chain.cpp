class Solution {
public:
    static bool orderLen(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    bool check(string s1, string s2){
        if(s1.size()-s2.size() != 1){
            return false;
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < s1.size()){
            
            if(s1[i] != s2[j] && count == 0){
                i++;
                count++;
            }
            else if(s1[i] != s2[j] && count > 0){
                return false;
            }
            else{
                i++;
                j++;
            }
            
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), orderLen);
        int ans = 0;
        // int j = words.size()-1;
        int temp = 0;
        unordered_map<string, int>mp;
        for(int i=0; i<words.size(); i++){
            // mp[words[i]]++;
            int max_temp = 0;
            for(int j=0; j<words[i].size(); j++){
                string temp = words[i].substr(0, j)+words[i].substr(j+1);
                mp[words[i]] = max(mp[words[i]], mp.find(temp) == mp.end() ? 1 : mp[temp]+1);
            }
            ans = max(ans, mp[words[i]]);
        }
        return ans;
    }
};