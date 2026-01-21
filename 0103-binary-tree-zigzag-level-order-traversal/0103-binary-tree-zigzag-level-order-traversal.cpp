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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;

        q.push(root);
        bool flag=false;

        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n);

            for(int i=0; i<n; i++){
                TreeNode* curr=q.front();
                q.pop();

                int idx = (flag==false) ? i : n-1-i;
                temp[idx]=curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(temp);
            flag=!flag;
        }
        return res;
    }
};