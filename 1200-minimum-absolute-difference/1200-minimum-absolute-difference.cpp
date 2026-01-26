class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int minDiff=INT_MAX;

        for(int i=1; i<n; i++){
            minDiff=min(minDiff, arr[i] - arr[i-1]);
        }

        for(int i=1; i<n; i++){
            vector<int> temp;
            if(arr[i] - arr[i-1]==minDiff){
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);

                res.push_back(temp);
            }      
        }   
        return res;
    }
};