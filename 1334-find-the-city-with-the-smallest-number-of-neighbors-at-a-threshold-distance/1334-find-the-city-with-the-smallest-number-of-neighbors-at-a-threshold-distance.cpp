class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        for(int i=0; i<n;i++){
            dist[i][i]=0;
        }

        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            dist[u][v]=w;
            dist[v][u]=w;
        }

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via]!=INT_MAX && dist[via][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int minNeighbours=INT_MAX;
        int city=0;

        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minNeighbours){
                minNeighbours=cnt;
                city=i;
            }
        }
        return city;
    }
};