class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;

    int find(int x){
        if(parent[x]!=x) 
            return parent[x]=find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y){
        if(find(x)==find(y)) return;

        if(rank[find(x)]>rank[find(y)]){
            parent[find(y)]=find(x);
        }

        else if(rank[find(x)]<rank[find(y)]){
            parent[find(x)]=find(y);
        }

        else{
            parent[find(x)]=find(y);
            rank[find(y)]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i, j);
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        int ans=n-cnt;

        return ans;
    }
};