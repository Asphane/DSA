class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> res;

        if (!root) return res;

        q.push({root, {0, 0}}); // node, {column, row}

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int col = front.second.first;
            int row = front.second.second;

            mp[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        for (auto &c : mp) {
            vector<int> column;
            for (auto &r : c.second) {
                column.insert(column.end(), r.second.begin(), r.second.end());
            }
            res.push_back(column);
        }

        return res;
    }
};
