class Solution {
public:
    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            if(grid[i][0]==1){
                q.push({i, 0});
                grid[i][0]=0;
            }

            if(grid[i][n-1]==1){
                q.push({i, n-1});
                grid[i][n-1]=0;
            }
        }

        for(int j=0; j<n; j++){
            if(grid[0][j]==1){
                q.push({0, j});
                grid[0][j]=0;
            }

            if(grid[m-1][j]==1){
                q.push({m-1, j});
                grid[m-1][j]=0;
            }
        }

        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();

            for(auto &d: directions){
                int n_i=i+d[0];
                int n_j=j+d[1];

                if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && grid[n_i][n_j]==1){
                    q.push({n_i, n_j});
                    grid[n_i][n_j]=0;
                }
            }
        }

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};