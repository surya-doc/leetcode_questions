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
    int getLHeight(TreeNode* root){
        if(!root) return 0;
        return 1+getLHeight(root->left);
    }
    
    int getRHeight(TreeNode* root){
        if(!root) return 0;
        return 1+getRHeight(root->right);
    }
    
    int getCount(TreeNode* root){
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        // if(root->left != NULL && root->right == NULL){
        //     return 2;
        // }
        int lheight = getLHeight(root->left);
        int rheight = getRHeight(root->right);
        if(lheight == rheight){
            return pow(2, 1+(lheight))-1;
        }
        else{
            return getCount(root->left)+getCount(root->right)+1;
        }
    }
    
    int countNodes(TreeNode* root) {
        return getCount(root);
    }
};