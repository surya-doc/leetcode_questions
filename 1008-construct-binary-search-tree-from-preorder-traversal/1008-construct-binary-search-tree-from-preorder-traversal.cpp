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
    TreeNode* constructTree(vector<int> &ele, int& l, int r){
        if(l==ele.size() || ele[l]>r) return NULL;
        TreeNode* temp = new TreeNode(ele[l++]);
        temp->left = constructTree(ele, l, temp->val);
        temp->right = constructTree(ele, l, r);
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return constructTree(preorder, i, INT_MAX);
    }
};