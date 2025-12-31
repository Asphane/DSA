class Solution {
public:
    int R, C;
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool DFS(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=R || j<0 || j>=C || grid[i][j]==1)
            return false;

        if(i==R-1)
            return true;

        grid[i][j]=1;

        for(auto &dir: directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            if(DFS(grid, new_i, new_j))
                return true;
        }
        return false;
    }

    bool cross(vector<vector<int>>& cells, int days){
        vector<vector<int>> grid(R, vector<int>(C));

        for(int i=0; i<=days; i++){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;

            grid[r][c]=1;
        }

        for(int j=0; j<C; j++){
            if(grid[0][j]==0 && DFS(grid, 0, j)){
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R=row;
        C=col;
        int l=0;
        int r=cells.size()-1;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(cross(cells, mid)){
                ans=mid+1;
                l=mid+1;
            }

            else{
                r=mid-1;
            }
        }
        return ans;
    }
};