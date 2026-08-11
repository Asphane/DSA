class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int sum=0, minSum=0;

        for(int val: nums){
            sum+=val;
            minSum=min(minSum, sum);
        }
        return 1-minSum;
    }
};