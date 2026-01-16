class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int val: asteroids){
            bool alive=true;
            while(alive && !st.empty() && st.top()>0 && val<0){
                if(st.top()<abs(val)){
                    st.pop();
                }

                else if(st.top()==abs(val)){
                    alive=false;
                    st.pop();
                }

                else{
                    alive=false;
                }
            }

            if(alive){
                st.push(val);
            }
        }

        vector<int> res(st.size());

        for(int i=st.size()-1; i>=0; i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};