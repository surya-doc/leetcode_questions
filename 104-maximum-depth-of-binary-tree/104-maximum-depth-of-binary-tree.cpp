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
    int getDepth(TreeNode* root, int length){
        if(!root){
            return length;
        }
        return max(getDepth(root->left, length+1), getDepth(root->right, length+1));
    }
    
    int maxDepth(TreeNode* root) {
        return getDepth(root, 0);
    }
};