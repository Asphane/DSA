class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int i=0;
        int ans=INT_MIN;

        while(i<n){
            curr+=nums[i];
            ans=max(curr, ans);

            if(curr<0){
                curr=0;
            }
            i++;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};