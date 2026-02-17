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
    void solve(TreeNode* root, vector<int> &res){
        if(!root) return;

        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }

        solve(root->left, res);
        solve(root->right, res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;

        solve(root1, res1);
        solve(root2,res2);

        return res1 == res2;
    }
};