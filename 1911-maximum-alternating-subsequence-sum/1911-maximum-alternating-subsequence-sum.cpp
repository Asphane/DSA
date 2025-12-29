class Solution {
public:
    int n;
    // long long dp[100001][2];

    // long long solve(vector<int>& nums, int idx, int flag){
    //     if(idx==n) return 0;

    //     if(dp[idx][flag]!=-1)
    //         return dp[idx][flag];

    //     long long val=nums[idx];

    //     long long skip=solve(nums, idx+1, flag);

    //     if(!flag)
    //         val=-val;

    //     long long take=solve(nums, idx+1, !flag)+val;

    //     return dp[idx][flag]=max(take, skip);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

        for(int i=1; i<n+1; i++){
            dp[i][0]=max(dp[i-1][1]-nums[i-1], dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+nums[i-1], dp[i-1][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};