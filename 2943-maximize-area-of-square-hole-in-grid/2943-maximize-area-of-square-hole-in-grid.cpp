class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int removable_v=1;
        int removable_h=1;

        int curr_h=1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1]==1){
                curr_h++;
            }

            else{
                curr_h=1;
            }
            removable_h=max(removable_h, curr_h);
        }

        int curr_v=1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1]==1){
                curr_v++;
            }

            else{
                curr_v=1;
            }
            removable_v=max(removable_v, curr_v);
        }
        
        int side=min(removable_h+1, removable_v+1);

        return side*side;
    }
};