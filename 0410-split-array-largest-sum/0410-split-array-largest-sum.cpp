class Solution {
public:

    bool check(vector<int> &nums, int k, int mid, int n){
        int pages=0;
        int students=1;
        
        for(int i=0; i<n; i++){
            if(pages + nums[i]> mid){
                students++;
                pages = nums[i];
            }
            
            else{
               pages+=nums[i]; 
            }
        }
        return students<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(), nums.end());
        int r=0;
        int ans=-1;
        
        for(int val: nums){
            r+=val;
        }
        
        if(k>n)
            return -1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(check(nums, k, mid, n)){
                ans=mid;
                r=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};