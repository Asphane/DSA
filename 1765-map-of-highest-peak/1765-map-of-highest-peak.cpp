class Solution {
public:
    int m, n;
    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m=isWater.size();
        n=isWater[0].size();

        vector<vector<int>> grid(m, vector<int>(n, -1));
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    grid[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int N=q.size();
            while(N--){
                pair<int, int> curr=q.front();
                q.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto &dir: directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==-1){
                        grid[new_i][new_j]=1+grid[i][j];
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return grid;
    }
};