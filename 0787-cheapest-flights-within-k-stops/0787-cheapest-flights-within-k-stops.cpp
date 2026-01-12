class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        int levels=0;

        for(auto &vec: flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        res[src]=0;

        while(!q.empty() && levels<=k){
            int N=q.size();
            while(N--){
                auto curr=q.front();
                q.pop();

                int node=curr.first;
                int cost=curr.second;

                for(auto &v:adj[node]){
                    if(cost+v.second < res[v.first]){
                        res[v.first]=cost+v.second;
                        q.push({v.first, cost+v.second});
                    }
                }
            }
            levels++;
        }
        return res[dst]==INT_MAX ? -1:res[dst];
    }
};