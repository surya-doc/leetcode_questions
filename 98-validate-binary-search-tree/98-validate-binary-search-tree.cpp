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
    bool desicionFinding(TreeNode* root, TreeNode* lt, TreeNode* rt){
        if(!root) return true;
        if((lt && root->val <= lt->val) || (rt && root->val >= rt->val)){
            return false;
        }
        return (desicionFinding(root->left, lt, root) && desicionFinding(root->right, root, rt));
        // return return_val;
    }
    bool isValidBST(TreeNode* root) {
        return desicionFinding(root, NULL, NULL);
    }
};