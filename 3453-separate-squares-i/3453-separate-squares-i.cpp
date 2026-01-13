class Solution {
public:

    bool check(vector<vector<int>>& squares, double total_area, double y_){
        double bot_area=0.0000;
        for(auto &sq: squares){
            double y=sq[1];
            double l=sq[2];

            double bottom_y=y;
            double top_y=y+l;

            if(y_>=top_y){
                bot_area+=l*l;
            }

            else if(y_>=bottom_y){
                bot_area+=l*(y_-y);
            }
        }
        return bot_area>=(total_area)/2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low=INT_MAX;
        double high=INT_MIN;
        double total_area=0.0000;

        for(auto &sq: squares){
            double x=sq[0];
            double y=sq[1];
            double l=sq[2];

            low=min(low, y);
            high=max(high, y+l);
            total_area+=l*l;
        }

        double res=0.0000;
 
        while(high-low>=1e-5){
            double mid=low+(high-low)/2;
            res=mid;

            if(check(squares, total_area, mid)){
                high=mid;
            }

            else{
                low=mid;
            }
        }
        return res;
    }
};