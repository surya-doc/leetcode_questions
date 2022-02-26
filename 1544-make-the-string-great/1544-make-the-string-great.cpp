class Solution {
public:
    string makeGood(string s) {
        for(int i=0; i<s.length(); i++){
            if(s[i]+32 == s[i+1] || s[i]-32 == s[i+1]){
                return makeGood(s.substr(0, i)+s.substr(i+2));
            }
        }
        return s;
    }
};