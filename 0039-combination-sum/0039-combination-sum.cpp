class Solution {
public:
    vector<vector<int>> ans;
    int sum=0;

    void solve(vector<int>& candidates, int target, int i, vector<int>& temp, int sum) {
        if (i == candidates.size()){
            if (sum == target)
                ans.push_back(temp);
            return;
        }

        solve(candidates, target, i + 1, temp, sum);
        
        if(sum + candidates[i] <= target){
            temp.push_back(candidates[i]);
            sum+=candidates[i];

            solve(candidates, target, i, temp, sum);

            temp.pop_back();
            sum-=candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp, sum);
        return ans;
    }
};
