/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> curnt_level;
            for(int i=0; i<len; i++){
                Node *temp = q.front();
                q.pop();
                curnt_level.push_back(temp->val);
                for(auto it:temp->children){
                    q.push(it);
                }
            }
            ans.push_back(curnt_level);
        }
        return ans;
    }
};