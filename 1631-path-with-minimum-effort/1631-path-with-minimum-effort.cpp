class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> grid(m, vector<int> (n, INT_MAX));

        pq.push({0, {0, 0}});
        grid[0][0]=0;

        auto isSafe=[&](int x, int y){
            return x>=0 && y>=0 && x<m && y<n;
        };

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int diff=curr.first;
            auto node=curr.second;

            int x=node.first;
            int y=node.second;

            for(auto &dir: directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];

                if(isSafe(new_x, new_y)){
                    int newDiff=max(diff, abs(heights[new_x][new_y]-heights[x][y]));
                    if(newDiff<grid[new_x][new_y]){
                        grid[new_x][new_y]=newDiff;
                        pq.push({newDiff, {new_x, new_y}});
                    }
                }
            }
        }
        return grid[m-1][n-1];
    }
};