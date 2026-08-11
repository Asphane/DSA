class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0, left=0, ans=0;

        for(int val: nums){
            sum+=val;
        }

        for(int i=0; i<n-1; i++){
            left+=nums[i];
            long long right=sum-left;

            if(left>=right){
                ans++;
            }
        }
        return ans;
    }
};