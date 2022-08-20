class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int one = 0;
        int zero = 0;
        string temp = "";
        int ans = 0;
        map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                one++;
            }
            else if(s[i] == '0'){
                zero++;
                mp[zero] = i;
            }
        }
        for(int i=0; i<one; i++){
            temp += '1';
        }
        for(int i=0; i<zero; i++){
            temp += '0';
        }
        while(1){
            if(s == temp){
                break;
            }
            for(int i=0; i<s.size()-1; i++){
                if(s[i] == '0' && s[i+1] == '1'){
                    swap(s[i], s[i+1]);
                    i++;
                }
            }
            ans++;
        }
        return ans;
    }
};