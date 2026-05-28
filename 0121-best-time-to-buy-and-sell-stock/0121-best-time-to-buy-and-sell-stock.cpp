class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minStock=INT_MAX;
        int maxP=0;

        for(int val: prices){
            minStock=min(minStock, val);
            maxP=max(maxP, val-minStock);
        }
        return maxP;
    }
};