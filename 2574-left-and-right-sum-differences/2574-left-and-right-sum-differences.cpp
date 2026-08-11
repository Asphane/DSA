class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0, left=0;
        vector<int> ans;

        for(int val: nums){
            sum+=val;
        }

        for(int i=0; i<n; i++){
            int right=sum-(left+nums[i]);
            ans.push_back(abs(right-left));
            left+=nums[i];
        }
        return ans;
    }
};