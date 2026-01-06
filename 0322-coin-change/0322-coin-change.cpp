class Solution {
public:
    int n;
    vector<int> dp;
    const int INF=1e9;

    int solve(vector<int> &coins, int amount){
        if(amount==0){
            return 0;
        }

        if(amount<0){
            return INF;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }

        int ans=INF;

        for(int &coin: coins){
            ans=min(ans, 1+solve(coins, amount-coin));
        }

        return dp[amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.resize(amount+1, -1);
        int res = solve(coins, amount);

        return res==INF ? -1 : res;
    }
};