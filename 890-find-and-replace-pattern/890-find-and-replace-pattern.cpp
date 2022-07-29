class Solution {
public:
    
    bool res(string s1, string s2){
        map<char, char> mp1;
        map<char, char> mp2;
        for(int i=0; i<s1.size(); i++){
            if(mp1.find(s1[i]) == mp1.end()){
                mp1[s1[i]] = s2[i];
            }
            if(mp2.find(s2[i]) == mp2.end()){
                mp2[s2[i]] = s1[i];
            }
        }
        string temp1 = "";
        string temp2 = "";
        for(int i=0; i<s1.size(); i++){
            temp1 += mp1[s1[i]];
            temp2 += mp2[s2[i]];
        }
        cout << temp1 << " " << temp2 << "\n";
        if(temp1 == s2 && temp2 == s1){
            return true;
        }
        return false;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            if(res(pattern, words[i])){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};