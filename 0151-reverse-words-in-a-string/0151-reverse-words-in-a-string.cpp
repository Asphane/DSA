class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=n-1;
        string word="";
        string res="";

        while(i>=0){
            while(i>=0 && s[i]==' '){
                    i--;
            }

            if(i<0){
                break;
            }

            int end=i;
            while(i>=0 && s[i]!=' '){
                    i--;
            }
            
            word=s.substr(i+1, end-i);
            if(!res.empty()){
                res+=" ";
            }

            res+=word;
        }
        return res;
    }
};