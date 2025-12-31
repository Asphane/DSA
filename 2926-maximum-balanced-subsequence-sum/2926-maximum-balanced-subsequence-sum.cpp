class Solution {
public:
    int n;
    //int dp[1000001][1000001];

    // long long solve(vector<int> &nums, int idx, int prev){
    //     if(idx>=n)
    //         return 0;

    //     if(prev!=-1 && dp[idx][prev]!=-1){
    //         return dp[idx][prev];
    //     }

    //     long long take=INT_MIN;
    //     long long leave=INT_MIN;

    //     if(prev==-1 || nums[idx]-idx>=nums[prev]-prev){
    //         take=nums[idx]+solve(nums, idx+1, idx);
    //     }
    //     leave=solve(nums, idx+1, prev);

    //     if(prev!=-1)
    //         dp[idx][prev]=max<long long>(take, leave);

    //     return max<long long>(take, leave);
    // }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n=nums.size();
        map<int, long long> mp;
        long long res=INT_MIN;

        for(int i=0; i<n; i++){
            auto it=mp.upper_bound(nums[i]-i);
            long long sum=nums[i];

            if(it!=mp.begin()){
                it--;
                sum+=it->second;
            }
            mp[nums[i]-i]=max(mp[nums[i]-i], sum);

            it=mp.upper_bound(nums[i]-i);
            while(it!=mp.end() && it->second<=sum){
                mp.erase(it++);
            }
            res=max(res, sum);
        }
        return res;
    }
};