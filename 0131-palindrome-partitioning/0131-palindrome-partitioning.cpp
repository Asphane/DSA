class Solution {
public:
    // vector<vector<string>> ans;
    // bool isValid(string &s, int l, int r){
    //     while(l<r){
    //         if(s[l]!=s[r]){
    //             return false;
    //         }
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    // void solve(string &s, vector<string> &curr, int idx){
    //     if(idx==s.size()){
    //         ans.push_back(curr);
    //         return;
    //     }

    //     for(int i=idx; i<s.size(); i++){
    //         if(isValid(s, idx, i)){
    //             curr.push_back(s.substr(idx, i-idx+1));
    //             solve(s, curr, i+1);
    //             curr.pop_back();
    //         }
    //     }
    // }
    // vector<vector<string>> partition(string s) {
    //     vector<string> curr;

    //     solve(s, curr, 0);
    //     return ans;
    // }

    void solve(string &s, vector<string> &curr, int i, vector<vector<string>> &res, vector<vector<bool>> &dp){
        if(i==s.length()){
            res.push_back(curr);
            return;
        }

        for(int j=i; j<s.length(); j++){
            if(dp[i][j]==true){
                curr.push_back(s.substr(i, j-i+1));
                solve(s, curr, j+1, res, dp);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<string> curr;
        vector<vector<string>> res;

        for(int i=0; i<n; i++){
            dp[i][i]=true;
        }

        for(int L=2; L<=n; L++){
            for(int i=0; i<n-L+1; i++){
                int j=i+L-1;

                if(s[i]==s[j]){
                    if(L==2){
                        dp[i][j]=true;
                    }

                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }

                }
            }
        }

        solve(s, curr, 0, res, dp);
        return res;
    }
};