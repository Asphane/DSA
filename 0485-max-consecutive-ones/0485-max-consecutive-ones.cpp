class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=-1;
        int cnt=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
                maxi=max(maxi, cnt);
            }

            else if(nums[i] != 1){
                cnt=0;
            }
        }
        return maxi == -1 ? 0 : maxi;
    }
};