class Solution {
public:
    int m, n;
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int steps=1;
        queue<pair<int, int>> q;

        if(grid[0][0]==1){
            return -1;
        }

        auto isSafe=[&](int x, int y){
            return x>=0 && y>=0 && x<m && y<n;
        };

        q.push({0, 0});
        grid[0][0]=1;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                pair<int, int> curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;

                if(x==m-1 && y==n-1){
                    return steps;
                }

                for(auto &dir: directions){
                    int new_i=x+dir[0];
                    int new_j=y+dir[1];

                    if(isSafe(new_i, new_j) && grid[new_i][new_j]==0){
                        q.push({new_i, new_j});
                        grid[new_i][new_j]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};