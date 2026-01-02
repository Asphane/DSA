class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;

        for(int val: nums){
            if(val==1){
                cnt++;
                ans=max(ans, cnt);
            }

            else{
                cnt=0;
            }
        }
        return ans;
    }
};