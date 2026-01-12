class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &vec: times){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        priority_queue<pair<int, int>> q;
        q.push({k, 0});
        res[k]=0;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto curr=q.top();
                q.pop();

                int node=curr.first;
                int time=curr.second;

                for(auto &v: adj[node]){
                    if(time+v.second < res[v.first]){
                        res[v.first]=time+v.second;
                        q.push({v.first, time+v.second});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (res[i] == INT_MAX) return -1;
            ans = max(ans, res[i]);
        }
        return ans;
    }
};