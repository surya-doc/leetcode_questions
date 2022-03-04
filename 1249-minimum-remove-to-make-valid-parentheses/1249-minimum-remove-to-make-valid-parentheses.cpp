class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        stack<int>clDlt;
        int front = 0;
        int back = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
                front++;
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                    front--;
                }
                else{
                    back++;
                }
            }
                if(back > front){
                    clDlt.push(i);
                    back--;
                }
        }
        while(!st.empty()){
            s = s.substr(0, st.top())+s.substr(st.top()+1);
            st.pop();
        }
        
        while(!clDlt.empty()){
            s = s.substr(0, clDlt.top())+s.substr(clDlt.top()+1);
            clDlt.pop();
        }
        return s;
    }
};