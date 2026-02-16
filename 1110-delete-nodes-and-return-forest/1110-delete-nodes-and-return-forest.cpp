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
    TreeNode* solve(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &res){
        if(!root) return nullptr;

        root->left = solve(root->left, st, res);
        root->right = solve(root->right, st, res);

        if(st.find(root->val) != st.end()){
            if(root->left)
                res.push_back(root->left);
            
            if(root->right)
                res.push_back(root->right);
            return nullptr;
        }
        else{
            return root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st;

        for(int &nums: to_delete){
            st.insert(nums);
        }

        solve(root, st, res);

        if(st.find(root->val) == st.end()){
            res.push_back(root);
        }
        return res;
    }
};