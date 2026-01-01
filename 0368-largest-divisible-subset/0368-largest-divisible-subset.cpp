class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<int> res;

        int maxL=1;
        int last_chosen=0;

        // if(n==1)
        //     return {nums[0]};

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }

                if(maxL<dp[i]){
                    maxL=dp[i];
                    last_chosen=i;
                }
            }
        }

        while(last_chosen>=0){
            res.push_back(nums[last_chosen]);
            last_chosen=prev[last_chosen];
        }

        return res;
    }
};