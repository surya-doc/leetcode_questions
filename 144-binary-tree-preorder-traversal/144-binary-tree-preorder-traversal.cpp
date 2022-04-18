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
    void getPreTree(TreeNode *root, vector<int> &ans){
        if(!root){
            return;
        }
        ans.push_back(root->val);
        getPreTree(root->left, ans);
        getPreTree(root->right, ans);
    }
    
    void iterative(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            TreeNode* a = temp.top();
            temp.pop();
            ans.push_back(a->val);
            if(a->right){
                temp.push(a->right);
            }
            if(a->left){
                temp.push(a->left);
            }
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // getPreTree(root, ans);
        if(!root) return ans;
        iterative(root, ans);
        return ans;
    }
};