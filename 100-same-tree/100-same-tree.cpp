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
    void inOrder(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        ans.push_back(root->val);
        if(root->left){
            inOrder(root->left, ans);   
        }
        else{
            ans.push_back(-1);
        }
        if(root->right){
            inOrder(root->right, ans);
        }
        else{
            ans.push_back(-1);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vp;
        vector<int> vq;
        inOrder(p, vp);
        inOrder(q, vq);
        if(vp.size() != vq.size()) return false;
        for(int i=0; i<vp.size(); i++){
            cout << vp[i] << " ";
        }
        cout << "\n";
        for(int i=0; i<vq.size(); i++){
            cout << vq[i] << " ";
        }
        for(int i=0; i<vp.size(); i++){
            // cout << vp[i] << vq[i] << "\n";
            if(vp[i] != vq[i]){
                return false;
            }
        }
        return true;
    }
};