/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getInOrderTree(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        getInOrderTree(root->left, ans);
        ans.push_back(root->val);
        getInOrderTree(root->right, ans);
    }
    
    void inOrder(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> st;
        TreeNode* Node = root;
        // st.push(root);
        while(true){
            if(Node != nullptr){
                st.push(Node);
                Node = Node->left;
            }
            else{
                
            if(st.empty() == true) break;
            Node = st.top();
            st.pop();
            ans.push_back(Node->val);
            Node = Node->right;  
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        // getInOrderTree(root, ans);
        inOrder(root, ans);
        return ans;
    }
};