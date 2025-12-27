class Solution {
public:

    bool solve(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree){
        queue<int> q;
        int cnt=0;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(int &v: adj[curr]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt==numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec: prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return solve(adj, numCourses, indegree);
    }
};