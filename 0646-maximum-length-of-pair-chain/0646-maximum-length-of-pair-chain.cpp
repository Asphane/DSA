class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs, int idx, int prev){
        if(idx>=n) return 0;

        int take=0;

        if(prev!=-1 && dp[idx][prev]!=-1)
            return dp[idx][prev];

        if(prev==-1 || pairs[idx][0]>pairs[prev][1]){
            take=1+solve(pairs, idx+1, idx);
        }
        int leave=solve(pairs, idx+1, prev);

        if(prev!=-1)
            dp[idx][prev]=max(take, leave);

        return max(take, leave);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));

        return solve(pairs, 0, -1);
    }
};