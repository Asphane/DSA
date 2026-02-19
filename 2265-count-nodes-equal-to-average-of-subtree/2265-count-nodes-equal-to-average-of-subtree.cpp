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
    int res = 0;

    int find(TreeNode* root, int &count){
        if(!root) return 0;

        count++;
        int l = find(root->left, count);
        int r = find(root->right, count);

        return l + r + root->val;
    }

    void solve(TreeNode* root){
        if(!root) return;

        int cnt = 0;
        int totalSum = find(root, cnt);

        if(root->val == totalSum / cnt){
            res ++;
        }

        solve(root->left);
        solve(root->right);

    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};