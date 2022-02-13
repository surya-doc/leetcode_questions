class Solution {
public:
    // bool check(int i, int j, string s){
    //     set<char>st;
    //     for(int a=j; a<=i; a++){
    //         if(st.find(s[a]) != st.end()){
    //             return false;
    //         }
    //         st.insert(s[a]);
    //     }
    //     return true;
    // }
    int countGoodSubstrings(string s) {
        int i = 2;
        int j = 0;
        int ans = 0;
        for(; i<s.length(); i++,j++){
            cout << j;
            cout << s[j] << s[j+1] << s[i] << " ";
            if(s[j] != s[j+1] && s[j] != s[i] && s[j+1] != s[i]) ans++;
        }
        return ans;
    }
};