class Solution {
public:
    vector<string> possibleColours;
    const int M=1e9+7;
    vector<vector<int>> dp;

    void possibleRowColours(string rowColour, int remainingRows, char prevColour){
        if(remainingRows==0){
            possibleColours.push_back(rowColour);
            return;
        }

        for(char ch:{'R', 'G', 'B'}){
            if(ch==prevColour)
                continue;
            possibleRowColours(rowColour+ch, remainingRows-1, ch);
        }
    }

    int solve(int remainingCols, int prevIdx, int rows){
        if(remainingCols==0){
            return 1;
        }

        if(dp[remainingCols][prevIdx]!=-1){
            return dp[remainingCols][prevIdx];
        }

        string prevCol=possibleColours[prevIdx];
        int ways=0;

        for(int i=0; i<possibleColours.size(); i++){
            string currCol=possibleColours[i];
            bool valid=true;
            for(int j=0; j<rows; j++){
                if(prevCol[j]==currCol[j]){
                    valid=false;
                    break;
                }
            }

            if(valid){
                ways=(ways+solve(remainingCols-1, i, rows))%M;
            }
        }
        return dp[remainingCols][prevIdx]=ways;
    }

    int colorTheGrid(int m, int n) {
        possibleRowColours("", m, '#');
        int res=0;
        dp.assign(n, vector<int>(possibleColours.size(), -1));

        for(int i=0; i<possibleColours.size(); i++){
            res=(res+solve(n-1, i, m))%M;

        }
        return res;
    }
};