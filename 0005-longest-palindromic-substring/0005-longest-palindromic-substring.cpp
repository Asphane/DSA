class Solution {
public:
    int st=0;
    int maxLen=1;

    void expand(string &s, int l, int r){ 
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                maxLen=r-l+1;
                st=l;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n=s.size();

        for(int i=0; i<n; i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return s.substr(st, maxLen);
    }
};