class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int j = 0;

        for (int i = 1; i <= n && j < target.size(); i++) {
            ops.push_back("Push");
            if (i == target[j]) {
                j++;
            } else {
                ops.push_back("Pop"); // remove unwanted number
            }
        }
        return ops;
    }
};
