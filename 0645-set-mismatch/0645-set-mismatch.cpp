class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        int sum=0, curr_sum=0;

        for(int &val: nums){
            mp[val]++;
        }

        for(int i=0; i<n; i++){
            curr_sum+=nums[i];
        }

        for(int i=1; i<=n; i++){
            sum+=i;
        }

        int duplicated=0;

        for(auto &it: mp){
            if(it.second>1){
                duplicated=it.first;
            }
        }
        ans.push_back(duplicated);
        int missing=sum-curr_sum+duplicated;
        ans.push_back(missing);

        return ans;
    }
};