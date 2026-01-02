class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int &val: nums){
            mp[val]++;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(mp.find(i+1)==mp.end() && i+1<=n){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};