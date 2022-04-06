class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        deque<char> q;
        string ans = "";
        for(int i=0; i<strs[0].size(); i++){
            q.push_back(strs[0][i]);
        }
        for(int i=1; i<strs.size(); i++){
            int siz = q.size();
            int flag = 1;
            for(int j=0; j<siz; j++){
                if(q.front() == strs[i][j] && flag == 1){
                    q.push_back(q.front());
                    q.pop_front();
                }
                else{
                    q.pop_front();
                    flag = 0;
                }
            }
        }
        for(auto it:q){
            ans += it;
        }
        return ans;
    }
};