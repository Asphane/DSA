class Solution {
public: 
    int m;
    vector<vector<int>> dp;
    int solve1(vector<vector<int>>& fruits, int i, int j){
        int ans=0;

        for(int i=0; i<m; i++){
            ans+=fruits[i][i];
            fruits[i][i]=0;
        }
        return ans;
    }

    int solve2(vector<vector<int>>& fruits, int i, int j){
        if(i<0 || i>=m || j<0 || j>=m){
            return 0;
        }

        if(i>j || i==j){
            return 0;
        }

        if(i==m-1 && j==m-1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int bottomL=fruits[i][j]+solve2(fruits, i+1, j-1);
        int bottomD=fruits[i][j]+solve2(fruits, i+1, j);
        int bottomR=fruits[i][j]+solve2(fruits, i+1, j+1);

        return dp[i][j]=max({bottomL, bottomD, bottomR});
    }

    int solve3(vector<vector<int>>& fruits, int i, int j){
        if(i<0 || i>=m || j<0 || j>=m){
            return 0;
        }

        if(i<j || i==j){
            return 0;
        }

        if(i==m-1 && j==m-1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int bottomL=fruits[i][j]+solve3(fruits, i-1, j+1);
        int bottomD=fruits[i][j]+solve3(fruits, i, j+1);
        int bottomR=fruits[i][j]+solve3(fruits, i+1, j+1);

        return dp[i][j]=max({bottomL, bottomD, bottomR});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        m=fruits.size();
        dp.resize(m, vector<int>(m, -1));

        int child1=solve1(fruits, 0, 0);
        int child2=solve2(fruits, 0, m-1);
        int child3=solve3(fruits, m-1, 0);

        return child1+child2+child3;
    }
};