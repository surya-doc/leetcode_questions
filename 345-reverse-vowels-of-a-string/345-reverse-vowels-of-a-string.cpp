class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;
        mp['A']++;
        mp['E']++;
        mp['I']++;
        mp['O']++;
        mp['U']++;
        int i = 0, j = s.size()-1;
        while(i < j){
            if(mp[s[i]] && mp[s[j]]){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            if(!mp[s[i]]){
                i++;
            }
            if(!mp[s[j]]){
                j--;
            }
        }
        return s;
    }
};