class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0, pSum=0;
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int i=0; i<n; i++){
            pSum+=nums[i]%2;

            if(mp.count(pSum-k)){
                ans+=mp[pSum-k];
            }

            mp[pSum]++;
        }
        return ans;
    }
};