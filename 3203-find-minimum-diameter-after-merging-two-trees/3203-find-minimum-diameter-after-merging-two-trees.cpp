class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>> adj, int src){
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(src);
        visited[src] = true;
        int farthest = 0;
        int dist = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                int node = q.front();
                q.pop();

                farthest = node;

                for(auto &nbr: adj[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            if(!q.empty()){
                dist++;
            }
        }
        return {farthest, dist};
    }

    int findDist(unordered_map<int, vector<int>> adj){
        auto[farthestNode, dist] = BFS(adj, 0);
        auto[otherNode, dia] = BFS(adj, farthestNode);

        return dia;
    }

    unordered_map<int, vector<int>> buildADJ(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;

        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildADJ(edges1);
        unordered_map<int, vector<int>> adj2 = buildADJ(edges2);

        int d1 = findDist(adj1);
        int d2 = findDist(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combined});
    }
};