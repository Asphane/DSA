class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long ans=INT_MAX;

        for(int i=0; i<n-1; i++){
            if(i+k-1 < n){
                long long diff = nums[i+k-1] - nums[i];
                ans=min(ans, diff);
            }
        }
        return ans==INT_MAX ? 0:ans;
    }
};