class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.size() == 0){
                    ans++;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans+st.size();
    }
};