class Solution {
public:

    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    typedef pair<int, int> P;

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;

        queue<P> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    fresh++;
                }

                else if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

        if(fresh==0) return 0;

        int minutes=0;

        while(!q.empty()){
            int N=q.size();

            while(N--){
                P curr=q.front();

                int i=curr.first;
                int j=curr.second;
                q.pop();

                for(auto &dir: directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==1){
                        q.push({new_i, new_j});
                        grid[new_i][new_j]=2;
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return (fresh==0) ? minutes-1:-1;
    }
};