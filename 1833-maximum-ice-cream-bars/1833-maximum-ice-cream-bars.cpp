class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt=0;
        long long sum=0;
        sort(costs.begin(), costs.end());

        for(int val: costs){
            sum+=val;

            if(sum<=coins){
                cnt++;
            }
        }
        return cnt;
    }
};