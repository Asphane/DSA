class Solution {
public:
    int solve(vector<int> &res){
        stack<int> st;
        int area=0;

        for(int i=0; i<=res.size(); i++){
            int currHeight=(i==res.size()) ? 0:res[i];
            while(!st.empty() && res[st.top()]>currHeight){
                int top=st.top();
                st.pop();

                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                area=max(area, res[top]*width);
            }
            st.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> res(c, 0);
        int maxArea=0;

        for(int i=0; i<c; i++){
            res[i]=(matrix[0][i]=='1') ? 1:0;
        }
        maxArea=max(maxArea, solve(res));

        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]=='1'){
                    res[j]+=1;
                }
                else{
                    res[j]=0;
                }
            }
            maxArea=max(maxArea, solve(res));
        }
        return maxArea;
    }
};