class Solution {
public:
    int countBinarySubstrings(string s) {
        long long prev = 0;
        long long curr = 1;
        int i = 1;
        int n = s.size();
        int ans = 0;

        while(i<n){
            if(s[i] == s[i-1]){
                curr++;
            }

            else{
                ans += (int)min(curr, prev);
                prev = curr;
                curr = 1;
            }
            i++;
        }
        ans += (int)min(curr, prev);

        return ans;
    }
};