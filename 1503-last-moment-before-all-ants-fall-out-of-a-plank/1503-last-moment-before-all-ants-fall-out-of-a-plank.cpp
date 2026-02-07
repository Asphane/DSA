class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        for(int val: left){
            ans = max(ans, val);
        }

        for(int val: right){
            ans = max(ans, n - val);
        }

        return ans;
    }
};