class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visit;

    bool solve(vector<vector<int>> &adj, int src, int dest){
        if(src==dest){
            return true;
        }

        visit[src]=1;

        for(auto &nbr: adj[src]){
            if(!visit[nbr]){
                if(solve(adj, nbr, dest)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        visit.assign(n, 0);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return solve(adj, source, destination);
    }
};