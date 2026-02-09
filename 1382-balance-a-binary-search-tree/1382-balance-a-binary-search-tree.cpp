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
    void inorder(TreeNode* root, vector<int> &vec){
        if(!root) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    TreeNode* solve(int l, int r, vector<int> &vec){
        if(l > r)
            return nullptr;

        int mid = l + (r-l)/2;

        TreeNode* curr = new TreeNode(vec[mid]);

        curr->left = solve(l, mid-1, vec);
        curr->right = solve(mid+1, r, vec);

        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        int l = 0; 
        int r = vec.size()-1;

        return solve(l, r, vec);
    }
};