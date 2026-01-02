class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string &log : logs) {
            int id, time;
            string type;
            
            // Parse log
            int p1 = log.find(':');
            int p2 = log.rfind(':');
            id = stoi(log.substr(0, p1));
            type = log.substr(p1 + 1, p2 - p1 - 1);
            time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } 
            else { // end
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};
