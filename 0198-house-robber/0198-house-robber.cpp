class Solution {
public:
    int dp[1001];
    int solve(vector<int> &nums, int n, int i){
        if(i>=n) return 0;

        if(dp[i]!=-1) 
            return dp[i];

        int steal=nums[i]+solve(nums, n, i+2);
        int leave=solve(nums, n, i+1);

        return dp[i]=max(steal, leave);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, n, 0);
    }
};