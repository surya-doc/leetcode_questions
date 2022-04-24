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
    TreeNode* makeTree(vector<int> &post, int postSt, int postEd, vector<int> &in, int inSt, int inEd, map<int, int> &mp){
        if(postSt > postEd || inSt > inEd){
            return NULL;
        }
        TreeNode* root = new TreeNode(post[postEd]);
        int inPoint = mp[root->val];
        int siz = inPoint-inSt;
        // cout << inPoint << siz << "\n"; 
        root->left = makeTree(post, postSt, postSt+siz-1, in, inSt, inPoint-1, mp);
        root->right = makeTree(post, postSt+siz, postEd-1, in, inPoint+1, inEd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = makeTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};