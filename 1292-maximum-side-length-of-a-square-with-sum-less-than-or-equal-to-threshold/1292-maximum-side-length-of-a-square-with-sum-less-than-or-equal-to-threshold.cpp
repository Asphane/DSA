class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r=mat.size();
        int c=mat[0].size();
        int ans=0;

        vector<vector<int>> preSum(r, vector<int> (c, 0));

        preSum[0][0]=mat[0][0];

        for(int j=1; j<c; j++){
            preSum[0][j]=preSum[0][j-1]+mat[0][j];
        }

        for(int i=1; i<r; i++){
            preSum[i][0]=preSum[i-1][0]+mat[i][0];
        }

        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]+mat[i][j]-preSum[i-1][j-1];
            }
        }

        for(int side=0; side<min(r, c); side++){
            for(int i=0; i+side<r; i++){
               for(int j=0; j+side<c; j++){
                    int new_i=i+side;
                    int new_j=j+side;

                    int sum=preSum[new_i][new_j]
                            -(i>0 ? preSum[i-1][new_j]:0)
                            -(j>0 ? preSum[new_i][j-1]:0)
                            +(i>0 && j>0 ? preSum[i-1][j-1]:0);

                    if(sum<=threshold){
                        ans=max(ans, side+1);
                    }
                }    
            }
        }
        return ans;
    }
};