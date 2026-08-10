class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int zeroC=0;
        int oneC=0;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            if(nums[i]==0) zeroC++;
            else oneC++;

            int rem=zeroC-oneC;
            if(mp.find(rem)!=mp.end()){
                ans=max(ans, i-mp[rem]);
            }

            else if(rem==0){
                ans=max(ans, i+1);
                continue;
            }

            else{
                mp[rem]=i;
            }
        }
        return ans;
    }
};