class Solution {
public:
    int m, n;
    const int neg=-1e9;
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i==m || j==n){
            return neg;
        }

        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }

        int take=nums1[i]*nums2[j] + max(0, solve(nums1, nums2, i+1, j+1));
        int skip1=solve(nums1, nums2, i+1, j);
        int skip2=solve(nums1, nums2, i, j+1);

        return dp[i][j]=max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=INT_MIN;
            }
        }

        return solve(nums1, nums2, 0, 0);
    }
};