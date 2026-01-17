class Solution {
public:
    int M=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> s;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        for(int i=0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                int diff=hFences[j]-hFences[i];
                s.insert(diff);
            }
        }

        int len=0;
        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                int diff=vFences[j]-vFences[i];
                if(s.find(diff)!=s.end()){
                    len=max(len, diff);
                }
            }
        }
        int ans=(1LL*len*len)%M;
        return ans==0 ? -1:ans;
    }
};