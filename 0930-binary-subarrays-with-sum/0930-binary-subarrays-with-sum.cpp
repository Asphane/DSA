class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int pSum=0, ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int i=0; i<n; i++){
            pSum+=nums[i];

            if(mp.count(pSum-goal)){
                ans+=mp[pSum-goal];
            }
            mp[pSum]++;
        }
        return ans;
    }
};