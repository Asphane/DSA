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
    void solve(TreeNode* root, int sum, vector<int> &temp,vector<vector<int>> &res){
        if(!root)
            return;

        temp.push_back(root->val);

        if(!root->left && !root->right && root->val==sum){
            res.push_back(temp);
        }

        if(root->left) solve(root->left, sum-root->val, temp, res);
        if(root->right) solve(root->right, sum-root->val, temp, res);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;

        if(!root)
            return res;

        solve(root, targetSum, temp, res);
        return res;
    }
};