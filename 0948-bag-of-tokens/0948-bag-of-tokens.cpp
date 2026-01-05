class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int maxi_score=0;
        int score=0;

        sort(tokens.begin(), tokens.end());

        int i=0;
        int j=n-1;

        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                maxi_score=max(maxi_score, score);
                i++;
            }

            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }

            else{
                return maxi_score;
            }
        }
        return maxi_score;
    }
};