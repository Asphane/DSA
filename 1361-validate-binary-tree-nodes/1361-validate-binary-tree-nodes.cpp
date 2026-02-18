class Solution {
public:
    unordered_map<int, int> child_parent;
    unordered_map<int, vector<int>> parent_child;

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        for(int i=0; i<n; i++){
            int node = i;
            int leftC = leftChild[i];
                if(leftC != -1) 
                    parent_child[i].push_back(leftC);

            int rightC = rightChild[i];
                if(rightC != -1) 
                    parent_child[i].push_back(rightC);

            if(leftC != -1) {
                if(child_parent.count(leftC)){
                    return false;
                }
                child_parent[leftC] = node;
            }

            if(rightC != -1) {
                if(child_parent.count(rightC)){
                    return false;
                }
                child_parent[rightC] = node;
            }
        }

        int root = -1;
        int roots = 0;

        for(int i=0; i<n; i++){
            if(child_parent.find(i) == child_parent.end()){
                root = i;
                roots++;
            }
        }

        if(root == -1 || roots != 1) return false;

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(root);
        visited[root] = true;
        int cnt = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &v: parent_child[node]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt == n;
    }
};