class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0; i<n; i++){
            if(maxi < nums[i]){
                maxi=nums[i];
            }

            if(mini > nums[i]){
                mini=nums[i];
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] > mini && nums[i] < maxi){
                cnt++;
            }
        }
        return cnt;
    }
};