class Solution {
public:
    int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> res(n, LLONG_MAX);
        vector<int> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);

        for(auto &vec: roads){
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        res[0]=0;
        ways[0]=1;

        while(!q.empty()){
            auto curr=q.top();
            q.pop();

            int node=curr.second;
            long long time=curr.first;

            if (time>res[node]) continue;

            for(auto &v: adj[node]){
                int next=v.first;
                long long w=v.second;
                long long newTime=time+w;
                if(newTime < res[next]){
                    res[next]=newTime;
                    ways[next]=ways[node];
                    q.push({newTime, next});
                }

                else if(newTime == res[next]){
                    ways[next]=(ways[next]+ways[node])%M;
                }
            }
        }
        return ways[n-1];
    }
};