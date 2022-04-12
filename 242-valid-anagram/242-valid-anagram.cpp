class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>s_c;
        unordered_map<char, int>t_c;
        for(int i=0; i<s.size(); i++){
            s_c[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            t_c[t[i]]++;
        }
        
        if(s_c.size() != t_c.size()){
            return false;
        }
        else{
            for(auto it:s_c){
                if(it.second != t_c[it.first]){
                    return false;
                }
            }
        }
        return true;
    }
};