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
    int res;

    void solve(TreeNode* root, vector<int> &path){
        if(!root) return;

        path[root->val]++;

        if(!root->left && !root->right){
            int cnt = 0;
            for(int i=1; i<=9; i++){
                if(path[i] % 2 != 0){
                    cnt++;
                }
            }
            if(cnt <= 1){
                res++;
            }
        }
        
        solve(root->left, path);
        solve(root->right, path);

        path[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10, 0);
        solve(root, path);

        return res;
    }
};