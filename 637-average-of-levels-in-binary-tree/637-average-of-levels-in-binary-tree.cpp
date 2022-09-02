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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<double> a;
        while(!q.empty()){
            int len = q.size();
            double ans = 0;
            int n = 0;
            for(int i=0; i<len; i++){
                TreeNode *temp = q.front();
                ans += temp->val;
                n++;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            a.push_back(ans/n);
        }
        return a;
    }
};