class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                // if(i == s.size()-1) break;
                for(int j=0; j<temp.size(); j++){
                    st.push(temp[j]);
                }
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