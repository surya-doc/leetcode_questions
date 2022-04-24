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
    TreeNode* buildTreeNodes(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &mp){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preStart]);
        int inPoint = mp[pre[preStart]];
        int inSiz = inPoint-inStart;
        root->left = buildTreeNodes(pre, preStart+1, preStart+inSiz, in, inStart, inPoint-1, mp);
        root->right = buildTreeNodes(pre, preStart+inSiz+1, preEnd, in, inPoint+1, inEnd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        // TreeNode* root = new TreeNode(preorder[0]);
        return buildTreeNodes(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        // return root;
    }
};