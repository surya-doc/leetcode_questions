class Solution {
public:
    string largestOddNumber(string num) {
        int ans = -1;
        map<char, bool>mp;
        mp['0'] = false;
        mp['1'] = true;
        mp['2'] = false;
        mp['3'] = true;
        mp['4'] = false;
        mp['5'] = true;
        mp['6'] = false;
        mp['7'] = true;
        mp['8'] = false;
        mp['9'] = true;
        for(int i=num.size()-1; i>=0; i--){
            if(mp[num[i]]){
                ans = i;
                break;
            }
        }
        if(ans == -1) return "";
        return num.substr(0, ans+1);
    }
};