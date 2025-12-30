class Solution {
public:
    int N, M, K;
    int dp[52][101][52];
    int MOD=1e9+7;

    int solve(int idx, int maxSoFar, int cost){
        if(idx==N){
            if(cost==K){
                return 1;
            }
            return 0;
        }

        if(dp[idx][maxSoFar][cost]!=-1){
            return dp[idx][maxSoFar][cost];
        }

        int res=0;

        for(int i=1; i<=M; i++){
            if(i>maxSoFar){
                res=(res+solve(idx+1, i, cost+1))%MOD;
            }

            else{
                res=(res+solve(idx+1, maxSoFar, cost))%MOD;
            }
        }
        return dp[idx][maxSoFar][cost]=res%MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};