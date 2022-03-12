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
    vector<TreeNode*>arr;
    void getTheArr(TreeNode* root){
        if(root->left){
            getTheArr(root->left);
        }
        arr.push_back(root);
        if(root->right){
            getTheArr(root->right);
        }
    }
    
    TreeNode* getAns(int start, int end){
        if(start > end) return NULL;
        int mid = (end+start)/2;
        TreeNode* ans = arr[mid];
        ans->left = getAns(start, mid-1);
        ans->right = getAns(mid+1, end);
        return ans;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        getTheArr(root);
        // (arr.size()%2 == 0) ? arr.size()/2-1 : arr.size()/2;
        return getAns(0, arr.size()-1);
    }
};