class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ansRow=0;
        int ansCnt=0;
        int zeroCnt=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    zeroCnt++;
                }
                if(ansCnt < zeroCnt){
                    ansCnt=zeroCnt;
                    ansRow=i;
                }
            }
            zeroCnt=0;
        }
        return {ansRow, ansCnt};
    }
};