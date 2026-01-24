class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=INT_MIN;

        int i=0; 
        int j=n-1;

        while(i <= j){
            int sum=nums[i] + nums[j];
            ans=max(ans, sum);

            i++; j--;
        }
        return ans;
    }
};