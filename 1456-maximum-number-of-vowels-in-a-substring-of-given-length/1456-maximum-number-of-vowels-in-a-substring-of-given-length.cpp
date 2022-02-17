class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int tem_count = 0;
        int n = s.size();
        int i = 0, j = 0;
        for(; j<n; j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                tem_count++;
            }
            if(j-i+1 == k){
                ans = max(ans, tem_count);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    tem_count--;
                }
                i++;
            }
        }
        return ans;
    }
};