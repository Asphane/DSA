class Solution {
public:
    int m, n;
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        auto isSafe=[&](int x, int y){
            return x>=0 && y>=0 && x<m && y<n;
        };

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> res(m, vector<int> (n, INT_MAX));
        pq.push({0, {0, 0}});
        res[0][0]=0;

        while(!pq.empty()){
            int diff=pq.top().first;
            auto node=pq.top().second;
            pq.pop();

            int x=node.first;
            int y=node.second;

            for(auto &dir: directions){
                int new_i=x+dir[0];
                int new_j=y+dir[1];

                if(isSafe(new_i, new_j)){
                    int newDiff=max(diff, abs(heights[x][y]-heights[new_i][new_j]));

                    if(newDiff < res[new_i][new_j]){
                        res[new_i][new_j]=newDiff;
                        pq.push({res[new_i][new_j], {new_i, new_j}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};