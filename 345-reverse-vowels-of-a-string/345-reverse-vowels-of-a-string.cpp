class Solution {
public:
    
    bool mp(char a){
        if(a == 'a' ||a == 'e' ||a == 'i' ||a == 'o' ||a == 'u' ||a == 'A' ||a == 'E' ||a == 'I' ||a == 'O' ||a == 'U'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        // unordered_map<char, int> mp;
        // mp['a']++;
        // mp['e']++;
        // mp['i']++;
        // mp['o']++;
        // mp['u']++;
        // mp['A']++;
        // mp['E']++;
        // mp['I']++;
        // mp['O']++;
        // mp['U']++;
        int i = 0, j = s.size()-1;
        while(i < j){
            if(mp(s[i]) && mp(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            if(!mp(s[i])){
                i++;
            }
            if(!mp(s[j])){
                j--;
            }
        }
        return s;
    }
};