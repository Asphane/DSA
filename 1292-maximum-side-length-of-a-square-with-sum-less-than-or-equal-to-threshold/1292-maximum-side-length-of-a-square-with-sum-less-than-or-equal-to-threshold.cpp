class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r=mat.size();
        int c=mat[0].size();
        int ans=0;

        vector<vector<int>> preSum(r, vector<int>(c, 0));
        preSum[0][0]=mat[0][0];

        for(int i=1; i<c; i++){
            preSum[0][i]=mat[0][i]+preSum[0][i-1];
        }

        for(int i=1; i<r; i++){
            preSum[i][0]=mat[i][0]+preSum[i-1][0];
        }

        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]+mat[i][j]-preSum[i-1][j-1];
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                for(int k=0; k<min(r-i, c-j); k++){
                    int k_x=i+k;
                    int k_y=j+k;

                    int sum=preSum[k_x][k_y]-(i>0 ? preSum[i-1][k_y]:0) 
                            - (j>0 ? preSum[k_x][j-1]:0)
                            + (i>0 && j>0 ? preSum[i-1][j-1]:0);

                    if(sum<=threshold){
                        ans=max(ans, k+1);
                    }

                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};