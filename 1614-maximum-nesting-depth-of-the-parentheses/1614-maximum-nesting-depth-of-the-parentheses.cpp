class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int maxi=0;

        for(char ch: s){
            if(ch=='('){
                curr++;
                maxi=max(maxi, curr);
            }

            else if(ch==')'){
                curr--;
            }
        }
        return maxi;
    }
};