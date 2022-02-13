class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int>mp;
        vector<string>ans;
        if(s.length() < 10) return ans;
        int i = 0;
        int j=0;
        string temp = "";
        for(; i<10; i++){
            temp += s[i];
        }
        mp[temp]++;
        for(; i<s.length(); i++){
            temp = temp.substr(1, 10);
            temp += s[i];
            mp[temp]++;
        }
        for(auto it:mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};