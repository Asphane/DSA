class Solution {
public:

    bool check(vector<int>& nums, int threshold, int mid, int n){
        int ans=0;

        for(int i=0; i<n; i++){
            ans+=(nums[i]+mid-1)/mid;
        }
        return ans<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=*max_element(nums.begin(), nums.end());

        while(l<r){
            int mid=l+(r-l)/2;

            if(check(nums, threshold, mid, n)){
                r=mid;
            }

            else{
                l=mid+1;
            }
        }
        return r;
    }
};