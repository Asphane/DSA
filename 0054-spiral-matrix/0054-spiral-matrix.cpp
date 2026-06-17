class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r  = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;

        int srow = 0, erow = r-1;
        int scol = 0, ecol = c-1;

        while(srow <= erow && scol <= ecol){
            for(int i=scol; i<=ecol; i++){
                ans.push_back(matrix[srow][i]);
            }

            for(int i=srow+1; i<=erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            for(int i=ecol-1; i>=scol; i--){
                if(srow==erow){
                    break;
                }
                ans.push_back(matrix[erow][i]);
            }

            for(int i=erow-1; i>=scol+1; i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};