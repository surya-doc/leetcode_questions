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
    int ans = 0;
    void getPree(TreeNode* root, int &check){
        if(!root){
            return;
        }
        getPree(root->left, check);
        check--;
        if(check == 0){
            ans = root->val;
        }
        getPree(root->right, check);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        getPree(root, k);
        return ans;
    }
};