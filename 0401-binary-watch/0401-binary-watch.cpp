class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int hrs=0; hrs<=11; hrs++){
            for(int minutes=0; minutes<=59; minutes++){
                if(__builtin_popcount(hrs) + __builtin_popcount(minutes) == turnedOn){
                    string hour = to_string(hrs);
                    string minute = ((minutes < 10) ? "0" : "") + to_string(minutes);
                    res.push_back(hour + ":" + minute);
                }
            }
        }
        return res;
    }
};