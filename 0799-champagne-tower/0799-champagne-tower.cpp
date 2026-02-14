class Solution {
public:
    // double dp[101][101];

    // double solve(int poured, int i, int j){
    //     if(i < 0 || j < 0 || i > j){
    //         return 0.0;
    //     }

    //     if(i == 0 && j == 0){
    //         return poured;
    //     }

    //     if(dp[i][j] != -1.0)
    //         return dp[i][j];

    //     double top_left = max(0.0, (solve(poured, i-1, j-1) - 1) / 2.0);
    //     double top_right = max(0.0, (solve(poured, i-1, j) - 1) / 2.0);

    //     return dp[i][j] = top_left + top_right;
    // }

    double champagneTower(int poured, int query_row, int query_glass) {
        // for(int i = 0; i < 101; i++)
        //     for(int j = 0; j < 101; j++)
        //         dp[i][j] = -1.0;

        // return min(1.0, solve(poured, query_row, query_glass));

        double tower[102][102] = {0.0};
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};