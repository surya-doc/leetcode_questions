class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        int mismatch = st.size()/2;
        return (mismatch+1)/2;
    }
};