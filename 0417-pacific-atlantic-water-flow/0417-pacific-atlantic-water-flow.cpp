class Solution {
public:
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m, n;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &vis, int i, int j){
        vis[i][j]=true;

        for(auto &dir: directions){
            int n_i=i+dir[0];
            int n_j=j+dir[1];

            if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && !vis[n_i][n_j] && heights[n_i][n_j]>=heights[i][j]){
                dfs(heights, vis, n_i, n_j);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        vector<vector<bool>> pac(m, vector<bool> (n, false));
        vector<vector<bool>> atl(m, vector<bool> (n, false));

        for(int i=0; i<m; i++) dfs(heights, pac, i, 0);
        for(int i=0; i<n; i++) dfs(heights, pac, 0, i);

        for(int i=0; i<m; i++) dfs(heights, atl, i, n-1);
        for(int i=0; i<n; i++) dfs(heights, atl, m-1, i);

        vector<vector<int>> res;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};