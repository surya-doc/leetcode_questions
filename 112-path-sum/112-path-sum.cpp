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
    bool ans = false;
    
    bool checkSum(TreeNode *root, int sum, int targetSum){
        if(ans == true){
            return true;
        }
        if(!root){
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            if(sum+root->val == targetSum){
                ans = true;
                return true;
            }
            else{
                return false;
            }
        }
        bool l = checkSum(root->left, sum+root->val, targetSum);
        bool r = checkSum(root->right, sum+root->val, targetSum);
        return l||r;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root, 0, targetSum);
    }
};