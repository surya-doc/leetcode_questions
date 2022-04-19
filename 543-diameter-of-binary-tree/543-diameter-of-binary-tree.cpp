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
    int max_return = INT_MIN;
    int getEdge(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = getEdge(root->left);
        int right = getEdge(root->right);
        max_return = max(max_return, left+right);
        return 1+max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // int left = getLeftEdge(root);
        // int right = getRightEdge(root);
        getEdge(root);
        return max_return;
    }
};