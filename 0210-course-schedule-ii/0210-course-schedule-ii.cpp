class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(numCourses);
        vector<bool> visit(numCourses, false);
        vector<int> indeg(numCourses, 0);
        stack<int> st;
        vector<int> res;

        for(auto &vec: prerequisites){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        for(int i=0; i<indeg.size(); i++){
            if(indeg[i]==0){
                visit[i]=true;
                st.push(i);
            }
        }

        while(!st.empty()){
            int curr=st.top();
            st.pop();

            for(int &v: adj[curr]){
                if(!visit[v]){
                    indeg[v]--;
                    if(indeg[v]==0){
                        st.push(v);
                        visit[v]=true;
                    }
                }
            }
            res.push_back(curr);
        }
        if (res.size() != numCourses)
            return {};
            
        return res;
    }
};