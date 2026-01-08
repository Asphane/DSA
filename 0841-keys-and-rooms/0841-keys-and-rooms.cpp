class Solution {
public:
    vector<int> visit;
    void dfs(int i, vector<vector<int>>& rooms){
        visit[i]=1;

        for(int val: rooms[i]){
            if(!visit[val]){
                dfs(val, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visit.assign(n, 0);

        dfs(0, rooms);

        for(int i=0; i<n; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};