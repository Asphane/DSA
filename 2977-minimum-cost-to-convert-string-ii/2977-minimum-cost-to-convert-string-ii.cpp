class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    string srcStr, tarStr;
    unordered_map<string, vector<pair<string, ll>>> adj; //adj['bcd'] -> {('cde', 2)}
    set<int> validL;
    ll BIG = 1e10;
    vector<ll> dp;


    ll dijkstra(string &start, string &end){
        priority_queue<P, vector<P>, greater<P>> pq; //{cost, string}
        unordered_map<string, ll> res; //{string, cost}

        res[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            ll cost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end){
                break;
            }

            for(auto &e: adj[node]){
                string nbr = e.first;
                ll cost2 = e.second;

                if(!res.count(nbr) || cost2 + cost < res[nbr]){
                    res[nbr] = cost2 + cost;
                    pq.push({cost2 + cost, nbr});
                }
            }
        }

        ll finalCost = res.count(end) ? res[end] : BIG;
        return finalCost;
    }

    ll solve(int idx){
        if(idx >= srcStr.length())
            return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        ll min_cost = BIG;

        if(srcStr[idx] == tarStr[idx]){
            min_cost = solve(idx + 1);
        }

        for(auto &len: validL){
            if(idx + len > srcStr.length()){
                break;
            }

            string srcSub = srcStr.substr(idx, len);
            string tarSub = tarStr.substr(idx, len);

            if(!adj.count(srcSub))
                continue;

            ll minPath_Cost = dijkstra(srcSub, tarSub);

            if(minPath_Cost == BIG){
                continue;
            }

            min_cost = min(min_cost, minPath_Cost + solve(idx + len));
        }
        return dp[idx] = min_cost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        srcStr = source;
        tarStr = target;
        dp.assign(10001, -1);

        for(int i=0; i<original.size(); i++){
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto &s: original){
            validL.insert(s.length());
        }

        ll res = solve(0);

        return res==BIG ? -1 : res;
    }
};