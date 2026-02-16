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
    string res = "";
    void preorder(TreeNode* root){
        if(!root){
            res+= "null,";
            return;
        }

        res += to_string(root->val) + ",";
        preorder(root->left);
        preorder(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preorder(root);

        return res;
    }

    TreeNode* build(queue<string> &q){
        string val = q.front();
        q.pop();

        if(val == "null"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(q);
        root->right = build(q);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;

        while(getline(ss, item, ',')){
            q.push(item);
        }

        return build(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));