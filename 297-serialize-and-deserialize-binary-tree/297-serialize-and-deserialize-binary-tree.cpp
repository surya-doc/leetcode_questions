/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans_1 = "";
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != nullptr){
                ans_1.append(to_string(temp->val)+',');                
            }
            else{
                ans_1.append("#,");
            }

            if(temp != nullptr){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout << ans_1;
        return ans_1;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0 || data[0] == '#') return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                temp->left = nullptr;
            }
            else{
                TreeNode* root_temp_1 = new TreeNode(stoi(str));
                temp->left = root_temp_1;
                q.push(temp->left);
            }
            getline(s, str, ',');
            if(str == "#"){
                temp->right = nullptr;
            }
            else{
                TreeNode* root_temp_2 = new TreeNode(stoi(str));
                temp->right = root_temp_2;
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));