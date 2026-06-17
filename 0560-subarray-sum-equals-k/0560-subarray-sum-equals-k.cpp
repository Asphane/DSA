class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, cnt=0;
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int val: nums){
            sum+=val;

            if(mp.find(sum-k) != mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};