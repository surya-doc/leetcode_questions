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
    
    queue<TreeNode *> getLevel(TreeNode *root, int depth){
        int level = 2;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            if(level == depth){
                return q;
            }
            int len = q.size();
            for(int i=0; i<len; i++){
                TreeNode *a = q.front();
                q.pop();
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }
            }
            level++;
        }
        return q;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        else{
            queue<TreeNode *> temp = getLevel(root, depth);
            while(!temp.empty()){
                TreeNode *b = temp.front();
                TreeNode *l = nullptr;
                TreeNode *r = nullptr;
                if(b->left){
                    l = b->left;
                }
                if(b->right){
                    r = b->right;
                }
                b->left = new TreeNode(val);
                b->right = new TreeNode(val);
                if(l != nullptr){
                    b->left->left = l;
                }
                if(r != nullptr){
                    b->right->right = r;
                }
                temp.pop();
            }
        }
        return root;
    }
};