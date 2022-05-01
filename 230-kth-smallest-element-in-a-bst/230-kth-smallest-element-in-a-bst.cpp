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
    void getPree(TreeNode* root, vector<int> &stor, int &check){
        if(!root){
            return;
        }
        getPree(root->left, stor, check);
        // stor.push_back(root->val);
        check--;
        if(check == 0){
            ans = root->val;
        }
        getPree(root->right, stor, check);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> stor;
        getPree(root, stor, k);
        // return stor[k-1];
        return ans;
    }
};