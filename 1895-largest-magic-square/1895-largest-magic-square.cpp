class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> rowSum(m, vector<int>(n));
        vector<vector<int>> colSum(m, vector<int>(n));

        for(int r=0; r<m; r++){
            rowSum[r][0]=grid[r][0];
            for(int c=1; c<n; c++){
                rowSum[r][c]=grid[r][c]+rowSum[r][c-1];
            }
        }

        for(int c=0; c<n; c++){
            colSum[0][c]=grid[0][c];
            for(int r=1; r<m; r++){
                colSum[r][c]=grid[r][c]+colSum[r-1][c];
            }
        }

        for(int side=min(m, n); side>=2; side--){
            for(int i=0; i+side-1<m; i++){
                for(int j=0; j+side-1<n; j++){
                    int targetSum=rowSum[i][j+side-1]-(j>0 ? rowSum[i][j-1]:0);
                    bool allSame=true;

                    for(int r=i+1; r<i+side; r++){
                        int rSum=rowSum[r][j+side-1]-(j>0 ? rowSum[r][j-1]:0);
                        if(rSum!=targetSum){
                            allSame=false;
                            break;
                        }
                    }   

                    if(!allSame){
                        continue;
                    }

                    for(int c=j; c<j+side; c++){
                        int cSum=colSum[i+side-1][c]-(i>0 ? colSum[i-1][c]:0);
                        if(cSum!=targetSum){
                            allSame=false;
                            break;
                        }
                    }   

                    if(!allSame){
                        continue;
                    }

                    int diag=0;
                    int antiDiag=0;

                    for(int k=0; k<side; k++){
                        diag+=grid[i+k][j+k];
                        antiDiag+=grid[i+k][j+side-1-k];
                    }
                    if(diag==targetSum && antiDiag==targetSum){
                            return side;
                    }
                }
            }
        }
        return 1;
    }
};