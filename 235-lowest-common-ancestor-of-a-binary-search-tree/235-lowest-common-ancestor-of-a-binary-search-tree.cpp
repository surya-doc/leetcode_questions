/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        TreeNode* keep = root;
        TreeNode* ans = root;
        while(keep){
            if(p->val == keep->val || q->val == keep->val){
                ans = keep;
                break;
            }
            else if(p->val < keep->val && q->val > keep->val){
                ans = keep;
                break;
            }
            else if(q->val < keep->val){
                keep = keep->left;
            }
            else{
                keep = keep->right;
            }
        }
        return ans;
    }
};