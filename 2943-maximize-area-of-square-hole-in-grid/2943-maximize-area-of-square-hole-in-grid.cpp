class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxV=1;
        int maxH=1;

        int currV=1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1]==1){
                currV++;
            }

            else{
                currV=1;
            }
            maxV=max(maxV, currV);
        }

        int currH=1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1]==1){
                currH++;
            }

            else{
                currH=1;
            }
            maxH=max(maxH, currH);
        }
        int l=min(maxV, maxH)+1;
        return l*l;
    }
};