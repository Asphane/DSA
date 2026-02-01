class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int first_min = INT_MAX;
        int sec_min = INT_MAX;

        for(int i=1; i<n; i++){
            if(nums[i] < first_min){
                sec_min = first_min;
                first_min = nums[i];
            }

            else if(nums[i] < sec_min){
                sec_min = nums[i];
            }
        }
        return ans + first_min + sec_min;
    }
};