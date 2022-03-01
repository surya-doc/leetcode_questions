class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>st;
        vector<int>ans(T.size());
        for(int i=T.size()-1; i>=0; i--){
            while(!st.empty() && T[st.top()] <= T[i]){
                st.pop();
            }
            if(!st.empty()){
                cout << st.top();
                ans[i] = st.top()-i;
            }
            else{
                ans[i] = 0;
                cout << 0;
            }
            st.push(i);
        }
        st.push(1);
        cout << st.top();
        return ans;
    }
};