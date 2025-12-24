class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> indegree, outdegree;

        for(auto &vec: pairs){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        int stNode=pairs[0][0];

        for(auto &it: adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                stNode=node;
                break;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(stNode);

        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                st.push(adj[curr].back());
                adj[curr].pop_back();
            }

            else{
                path.push_back(curr);
                st.pop();
            }
        }

        vector<vector<int>> res;
        reverse(path.begin(), path.end());

        for(int i=0; i<path.size()-1; i++){
            res.push_back({path[i], path[i+1]});
        }
        return res;
    }
};