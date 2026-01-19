class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<int>> rowSum(r, vector<int>(c, 0));
        vector<vector<int>> colSum(r, vector<int>(c, 0));

        for(int i=0; i<r; i++){
            rowSum[i][0]=grid[i][0];
        }

        for(int i=0; i<r; i++){
            for(int j=1; j<c; j++){
                rowSum[i][j]=grid[i][j]+rowSum[i][j-1];
            }
        }

        for(int i=0; i<c; i++){
            colSum[0][i]=grid[0][i];
        }

        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                colSum[i][j]=grid[i][j]+colSum[i-1][j];
            }
        }

        for(int side=min(r, c); side>=2; side--){
            for(int i=0; i+side-1<r; i++){
                for(int j=0; j+side-1<c; j++){
                    int target=rowSum[i][j+side-1]-(j>0 ? rowSum[i][j-1]:0);
                    bool same=true;

                    for(int row=i+1; row<i+side; row++){
                        int sum=rowSum[row][j+side-1]-(j>0 ? rowSum[row][j-1]:0);

                        if(sum!=target){
                            same=false;
                            break;
                        }
                    }

                    if(!same) continue;

                    for(int col=j; col<j+side; col++){
                        int sum=colSum[i+side-1][col]-(i>0 ? colSum[i-1][col]:0);

                        if(sum!=target){
                            same=false;
                            break;
                        }
                    }

                    if(!same) continue;

                    int diag=0;
                    int antiDiag=0;
                    for(int k=0; k<side; k++){
                        diag+=grid[i+k][j+k];
                        antiDiag+=grid[i+k][j+side-1-k];    
                    }

                    if(diag==target && antiDiag==target){
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};