class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int x:nums){
            mp[x]++;
        }

        for(auto &p:mp){
            if(p.second > n/3){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};