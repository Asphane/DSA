class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int c=grid[0].size();
        int sq_n=n*n;

        vector<int> freq(sq_n+1, 0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<c; j++){
                freq[grid[i][j]]++;
            }
        }

        int rep=-1;
        int miss=-1;
        for(int i=1; i<sq_n+1; i++){
            if(freq[i] > 1){
                rep=i;
            }

            else if(freq[i]==0){
                miss=i;
            }
        }
        ans.push_back(rep);
        ans.push_back(miss);
        return ans;
    }
};