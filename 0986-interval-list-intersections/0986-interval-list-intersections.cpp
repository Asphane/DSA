class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0;
        int j=0;
        vector<vector<int>> res;

        while(i<firstList.size() && j<secondList.size()){
            int st=max(firstList[i][0], secondList[j][0]);
            int e=min(firstList[i][1], secondList[j][1]);

            if(st<=e){
                res.push_back({st, e});
            }

            if(firstList[i][1] < secondList[j][1]){
                i++;
            }

            else{
                j++;
            }
        }
        return res;
    }
};