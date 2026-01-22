class Solution {
public:
    int n;
    int check_idx(vector<int>& nums){
        int idx=-1;
        int ans=INT_MAX;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] < ans){
                idx=i;
                ans=nums[i] + nums[i+1];
            }
        }
        return idx;
    }  

    int minimumPairRemoval(vector<int>& nums) {
        int op=0;

        while(!is_sorted(nums.begin(), nums.end())){
            int idx=check_idx(nums);

            nums[idx]=nums[idx]+nums[idx+1];
            nums.erase(nums.begin() + idx+1);
            op++;
        }
        return op;
    }
};