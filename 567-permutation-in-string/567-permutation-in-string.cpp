class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp_smll(26);
        vector<int>temp(26);
        for(int i=0; i<s1.length(); i++){
            mp_smll[s1[i]-'a']++;
        }
        int window_len = 0;
        int j = 0;
        for(int i=0; i<s2.length(); i++){
            temp[s2[i]-'a']++;
            window_len++;
            if(temp == mp_smll){
                return true;
            }
            if(window_len > s1.length()-1){
                temp[s2[j]-'a']--;
                j++;
                window_len--;
            }
        }
        return false;
    }
};