class Solution {
public:

    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    typedef pair<int, int> P;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        queue<P> q;

        int stcolor=image[sr][sc];
    
        if(stcolor==color) return image;
        image[sr][sc]=color;
        q.push({sr, sc});
        

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

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && image[new_i][new_j]==stcolor){
                        q.push({new_i, new_j});
                        image[new_i][new_j]=color;
                    }
                }
            }
        }
        return image;
    }
};