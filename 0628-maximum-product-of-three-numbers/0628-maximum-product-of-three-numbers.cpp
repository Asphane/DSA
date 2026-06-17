class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();    
        sort(nums.begin(), nums.end());

        int max1 = nums[n-1];
        int max2 = nums[n-2];
        int max3 = nums[n-3];
        int min1 = nums[0];
        int min2 = nums[1];

        int prod1 = max1 * max2 * max3;
        int prod2 = min1 * min2 * max1;

        return max(prod1, prod2);
    }
};