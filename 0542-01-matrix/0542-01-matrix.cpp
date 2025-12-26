class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,int> P;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int> (n, -1));
        queue<P> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int N=q.size();
            while(N--){
                P curr=q.front();
                q.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto &dir: directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && res[new_i][new_j]==-1){
                        res[new_i][new_j]=res[i][j]+1;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
        return res;
    }
};