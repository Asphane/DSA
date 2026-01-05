class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        long long sum=0;
        int mini=INT_MAX;
        int nega=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum+=abs(matrix[i][j]);
                mini=min(mini, abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    nega++;
                }
            }
        }

        if(nega%2==0){
            return sum;
        }

        return sum-(2*mini);
    }
};