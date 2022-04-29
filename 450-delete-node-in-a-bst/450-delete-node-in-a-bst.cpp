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
    // int updateTree(TreeNode* root, int left, int right){
    //     if(root->right->left == NULL && root->right->right == NULL){
    //         int temp = root->right->val;
    //         root->right = NULL;
    //         return temp;
    //     }
    // }
    
//     void findVal(TreeNode* root, int val){
        
//         delete find;
//     }
    
    TreeNode* deleteNode(TreeNode* root, int val) {
        TreeNode* find = root;
        TreeNode* prev = nullptr;
        while(find && find->val != val){
            prev = find;
            if(find->val < val){
                find = find->right;
            }
            else{
                find = find->left;
            }
        }
        if(!find) return root;
        if(!find->right || !find->left){
                auto child = (find->left) ? find->left : find->right;
                if(!prev){
                    root = child;
                }
                else if(prev->left == find){
                    prev->left = child;
                }
                else{
                    prev->right = child;
                }
            }
        else{
            auto stor = find;
            prev = find;
            find = find->right;
            while(find->left){
                prev = find;
                find = find->left;
            }
            stor->val = find->val;
            if(prev->left == find){
                prev->left = find->right;
            }
            else{
                prev->right = find->right;
            }
        }
        return root;
    }
};