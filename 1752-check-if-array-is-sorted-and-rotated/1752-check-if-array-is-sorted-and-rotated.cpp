class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int j=0; j<n; j++){
            if(nums[j] > nums[(j+1)%n]){
                cnt++;
            }
        }
        return cnt<=1;
    }
};