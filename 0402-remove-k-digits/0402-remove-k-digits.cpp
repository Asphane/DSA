class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        if(num.size()==k) return "0";

        for(char ch: num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        
        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;
        } 
        res=res.substr(i);

        return res.empty() ? "0":res;
    }
};