class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> outdeg(n, 0);

        // Build reverse graph & outdegree
        for (int u = 0; u < n; u++) {
            outdeg[u] = graph[u].size();
            for (int v : graph[u]) {
                revAdj[v].push_back(u);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdeg[i] == 0)
                q.push(i);
        }

        vector<int> res;

        // Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (int parent : revAdj[node]) {
                outdeg[parent]--;
                if (outdeg[parent] == 0)
                    q.push(parent);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
