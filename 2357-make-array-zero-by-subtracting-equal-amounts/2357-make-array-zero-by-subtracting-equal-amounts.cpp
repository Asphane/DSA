class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;

        for(int val: nums){
            if(val!=0)
                s.insert(val);
        }
        return s.size();
    }
};