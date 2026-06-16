class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit = -1;
        int buyP = INT_MAX;

        for(int val: prices){
            if(val < buyP){
                buyP = val;
            }
            profit = max(profit, val - buyP);
        }
        return profit;
    }
};