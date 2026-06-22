class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int l=0;
        int h=n-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            int maxRow=0;
            for(int i=0; i<m; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow=i;
                }
            }

            int curr=mat[maxRow][mid];
            int left=(mid>0) ? mat[maxRow][mid-1] : -1;
            int right=(mid<n-1) ? mat[maxRow][mid+1] : -1;

            if(curr > left && curr > right){
                return{maxRow, mid};
            }

            else if(curr < left){
                h=mid-1;
            }

            else{
                l=mid+1;
            }
        }
        return {-1, -1};
    }
};