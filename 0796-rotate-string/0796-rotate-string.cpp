class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size();
        int n=goal.size();
        string temp=s+s;

        if(temp.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};