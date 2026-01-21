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
    int ans;

    int solve(TreeNode* root){
        if(!root)
            return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        int best=l+r+root->val;
        int either_one=max(l, r)+root->val;
        int only_root=root->val;

        ans=max({ans, best, either_one, only_root});

        return max(either_one, only_root);
    }

    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;

        solve(root);

        return ans;
    }
};