class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int curr;
        int cnt=0, i=0;

        while(i<n){
            if(cnt==0){
                curr=nums[i];
                cnt++;
            }

            else if(nums[i]!=curr){
                cnt--;
            }

            else{
                cnt++;
            }
            i++;
        }
        return curr;
    }
};