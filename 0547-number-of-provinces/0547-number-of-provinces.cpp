class Solution {
public:

    void solve(vector<vector<int>>& isConnected, int u, vector<bool> &visit){
        visit[u]=true;

        for(int v=0; v<isConnected.size(); v++){
            if(!visit[v] && isConnected[u][v]==1){
                solve(isConnected, v, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visit(isConnected.size(), false);
        int cnt=0;

        for(int i=0; i<isConnected.size(); i++){
            if(!visit[i]){
                solve(isConnected, i, visit);
                cnt++;
            }
        }
        return cnt;
    }
};