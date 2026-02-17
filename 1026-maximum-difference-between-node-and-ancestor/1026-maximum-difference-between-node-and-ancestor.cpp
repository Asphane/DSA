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
    int maxDiff(TreeNode* root, int maxV, int minV){
        if(!root){
            return abs(maxV - minV);
        }

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        int left = maxDiff(root->left, maxV, minV);
        int right = maxDiff(root->right, maxV, minV);

        return max(left, right);
    }   

    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root, root->val, root->val);
    }
};