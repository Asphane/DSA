class Solution {
public:
    int n;
    int dp[5001][301];

    int solve(int amount, vector<int>& coins, int i){
        if(amount==0){
            return 1;
        }

        if(i==n || amount<0){
            return 0;
        }

        if(dp[amount][i]!=-1){
            return dp[amount][i];
        }

        if(amount<coins[i]){
            return dp[amount][i]=solve(amount, coins, i+1);
        }

        int take=solve(amount-coins[i], coins, i);
        int leave=solve(amount, coins, i+1);

        return dp[amount][i]=take+leave;
    }

    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp, -1, sizeof(dp));

        return solve(amount, coins, 0);
    }
};