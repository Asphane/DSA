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
    void solve(TreeNode* root, string temp, vector<string> &res){
        if(!root)
            return;
        
        temp+=to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(temp);
            return;
        }

        temp+=("->");
        solve(root->left, temp, res);
        solve(root->right, temp, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;

        solve(root, "", res);
        return res;
    }
};