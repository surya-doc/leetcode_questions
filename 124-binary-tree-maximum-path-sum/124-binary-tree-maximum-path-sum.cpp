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
    int getMaxSum(TreeNode* root, int &ans){
        if(!root) return 0;
        int lsum = max(0, getMaxSum(root->left, ans));
        int rsum = max(0, getMaxSum(root->right, ans));
        int tot = root->val+lsum+rsum;
        // cout << tot << "\n"
        ans = max(ans, tot);
        return root->val+max(lsum, rsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getMaxSum(root, ans);
        return ans;
    }
};