class Solution {
public:
    int minimumMoves(string s) {
        int dv = s.size()/3;
        int remain = s.size()%3;
        int ans = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i] == 'O'){
                i++;
            }
            else{
                ans++;
                i += 3;
            }
        }
        return ans;
    }
};