class Solution {
public:
    int M=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> width;
        unordered_set<int> height;

        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                int diff=vFences[j]-vFences[i];
                width.insert(diff);
            }
        }

        int maxL=0;
        for(int i=0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                int diff=hFences[j]-hFences[i];
                if(width.find(diff)!=width.end()){
                    maxL=max(maxL, diff);
                }
            }
        }

        return maxL==0 ? -1:(1LL*maxL*maxL)%M;
    }
};