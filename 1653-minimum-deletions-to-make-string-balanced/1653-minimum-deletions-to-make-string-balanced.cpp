class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt = 0;

        for(char ch: s){
            if(!st.empty() && st.top() == 'b' && ch == 'a'){
                st.pop();
                cnt++;
            }
            else{
                st.push(ch);
            }
        }
        return cnt;
    }
};