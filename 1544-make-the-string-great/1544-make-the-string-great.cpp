class Solution {
public:
    string makeGood(string s) {
        // for(int i=0; i<s.length(); i++){
        //     if(s[i]+32 == s[i+1] || s[i]-32 == s[i+1]){
        //         return makeGood(s.substr(0, i)+s.substr(i+2));
        //     }
        // }
        // return s;
        stack<char>st;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && (st.top()+32 == s[i] || st.top()-32 == s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};