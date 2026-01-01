class Solution {
public:
    int n;
    // int dp[2501][2501];
    // int solve(vector<int> &nums, int idx, int prev){
    //     if(idx>=n) return 0;

    //     if(prev!=-1 && dp[idx][prev]!=-1) 
    //         return dp[idx][prev];

    //     int take=0;
    //     if(prev==-1 || nums[prev]<nums[idx])
    //         take=1+solve(nums, idx+1, idx);

    //     int leave=solve(nums, idx+1, prev);

    //     if(prev!=-1)
    //         dp[idx][prev]=max(take, leave);

    //     return max(take, leave);
    // }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        // memset(dp, -1, sizeof(dp));

        // return solve(nums, 0, -1);
        vector<int> sorted;

        for(int i=0; i<n; i++){
            auto it=lower_bound(sorted.begin(), sorted.end(), nums[i]);

            if(it==sorted.end())   
                sorted.push_back(nums[i]);

            else
                *it=nums[i];
        }
        return sorted.size();
    }
};