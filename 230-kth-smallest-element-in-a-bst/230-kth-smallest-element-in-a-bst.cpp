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
    void getPree(TreeNode* root, vector<int> &stor){
        if(!root){
            return;
        }
        getPree(root->left, stor);
        stor.push_back(root->val);
        getPree(root->right, stor);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> stor;
        getPree(root, stor);
        for(auto it:stor){
            cout << it;
        }
        return stor[k-1];
    }
};