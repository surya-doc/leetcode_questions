class Solution {
public:
    int evn(string s, int i){
        int j = i+1;
        int ans = 0;
        while(i >= 0 && j<= s.size()-1){
            if(s[i] == s[j]){
                ans++;
            }
            else{
                break;
            }
            i--;
            j++;
        }
        return ans;
    }
    
    int odd(string s, int i){
        int j = i;
        int ans = 0;
        while(i >= 0 && j<= s.size()-1){
            if(s[i] == s[j]){
                ans++;
            }
            else{
                break;
            }
            i--;
            j++;
        }
        return ans;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans += evn(s, i);
            ans += odd(s, i);
        }
        return ans;
    }
};