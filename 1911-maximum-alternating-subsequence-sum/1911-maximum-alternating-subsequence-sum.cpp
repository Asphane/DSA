class Solution {
public:
    int n;
    long long dp[100001][2];

    long long solve(vector<int>& nums, int idx, int flag){
        if(idx==n) return 0;

        if(dp[idx][flag]!=-1)
            return dp[idx][flag];

        long long val=nums[idx];

        long long skip=solve(nums, idx+1, flag);

        if(!flag)
            val=-val;

        long long take=solve(nums, idx+1, !flag)+val;

        return dp[idx][flag]=max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(dp, -1, sizeof(dp)); 
        bool flag=true;

        return solve(nums, 0, flag);
    }
};