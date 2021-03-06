class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int>stor;
        
        for(; i<pushed.size(); i++){
            while(!stor.empty() && stor.top() == popped[j]){
                stor.pop();
                j++;
            }
            stor.push(pushed[i]);
        }
        while(!stor.empty() && stor.top() == popped[j]){
            stor.pop();
            j++;
        }
        return stor.empty();
    }
};