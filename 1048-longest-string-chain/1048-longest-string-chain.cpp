class Solution {
public:
    int N;
    int dp[1001][1001];

    bool isPredecessor(string &pre, string &curr){
        int m=pre.length();
        int n=curr.length();

        if(m==n || (n-m)!=1) return false;
        int i=0, j=0;

        while(i<m && j<n){
            if(pre[i]==curr[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }

    int solve(vector<string> &words, int idx, int prev){
        if(idx>=N) return 0;

        if(prev!=-1 && dp[prev][idx]!=-1)
            return dp[prev][idx];

        int take=0;
        if(prev==-1 || isPredecessor(words[prev], words[idx]))
            take=1+solve(words, idx+1, idx);

        int leave=solve(words, idx+1, prev);

        if(prev!=-1)
            dp[prev][idx]=max(take, leave);

        return max(take, leave);
    }

    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        N=words.size();
        sort(words.begin(), words.end(), myFunction);
        memset(dp, -1, sizeof(dp));

        return solve(words, 0, -1);
    }
};