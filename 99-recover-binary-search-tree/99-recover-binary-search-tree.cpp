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
    private:
        TreeNode* fv;
        TreeNode* sv;
        TreeNode* prev;
        TreeNode* middle;
    private:
        void getInorder(TreeNode* root){
            if(!root){
                return;
            }
            getInorder(root->left);
            if(prev != NULL && root->val < prev->val){
                cout << root->val << prev->val << "\n";
                if(fv == NULL){
                    fv = prev;
                    middle = root;
                }
                else{
                    sv = root;
                }
            }
            prev = root;
            getInorder(root->right);
        }
public:
    void recoverTree(TreeNode* root) {
        fv = sv = prev = middle = NULL;
        prev = new TreeNode(INT_MIN);
        getInorder(root);
        if(fv && sv) swap(fv->val, sv->val);
        else if(fv && middle) swap(fv->val, middle->val);
    }
};