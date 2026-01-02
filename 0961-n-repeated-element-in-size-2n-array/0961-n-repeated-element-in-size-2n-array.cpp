class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;

        for(int &val: nums){
            mp[val]++;
        }

        int ans=0;
        for(auto &it: mp){
            if(it.second==n/2 && it.second==mp.size()-1){
                ans=it.first;
            }
        }
        return ans;
    }
};