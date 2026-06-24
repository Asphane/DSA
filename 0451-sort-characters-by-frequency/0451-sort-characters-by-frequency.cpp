class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string ans="";

        for(char ch: s){
            mp[ch]++;
        }

        for(auto &it: mp){
            pq.push({it.second, it.first});
        }

        while(!pq.empty()){
            ans+=string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};