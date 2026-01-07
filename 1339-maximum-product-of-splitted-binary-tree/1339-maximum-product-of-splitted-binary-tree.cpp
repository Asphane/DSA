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
    long long tot_sum=0;
    long long max_prdt=0;
    const int MOD=1e9+7;

    long long wholeDFSsum(TreeNode* root){
        if(!root){
            return 0;
        }

        return root->val + wholeDFSsum(root->left) + wholeDFSsum(root->right);
    }

    long long subtreeDFSsum(TreeNode* root){
        if(!root){
            return 0;
        }

        long long left=subtreeDFSsum(root->left);
        long long right=subtreeDFSsum(root->right);

        long long curr_sum=root->val + left + right;
        max_prdt=max(max_prdt, curr_sum*(tot_sum-curr_sum));

        return curr_sum;
    }

    int maxProduct(TreeNode* root) {
        tot_sum=wholeDFSsum(root);
        subtreeDFSsum(root);

        return max_prdt%MOD;
    }
};