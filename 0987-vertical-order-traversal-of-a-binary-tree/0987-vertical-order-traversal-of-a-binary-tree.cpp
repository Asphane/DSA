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
    map<int, map<int, vector<int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    vector<vector<int>> res;

    void solve(TreeNode* root){
        if(!root)
            return;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            TreeNode* curr = node.first;
            auto dist = node.second;

            int col = dist.first;
            int row = dist.second;

            mp[col][row].push_back(curr->val);

            if(curr->left)
                q.push({curr->left, {col-1, row+1}});

            if(curr->right)
                q.push({curr->right, {col+1, row+1}});
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return res;

        solve(root);

        for(auto &i: mp){
            for(auto &j: i.second){
                sort(j.second.begin(), j.second.end());
            }
        }

        for(auto i: mp){
            vector<int> temp_col;
            for(auto j: i.second){
                for(auto k: j.second){
                    temp_col.push_back(k);
                }
            }
            res.push_back(temp_col);
        }

        return res;
    }
};