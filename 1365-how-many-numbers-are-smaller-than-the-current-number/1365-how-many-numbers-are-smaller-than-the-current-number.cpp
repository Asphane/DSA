class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp=nums;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
        }

        for(int i=0; i<temp.size(); i++){
            if(mp.find(temp[i])!=mp.end()){
                ans.push_back(mp[temp[i]]);
            }
        }
        return ans;
    }
};