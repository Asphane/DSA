class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> dp;

    ll solve(vector<int>& nums, int i, int trend){
        if(i == n){
            if(trend == 3){
                return 0;
            }

            else{
                return LLONG_MIN/2;
            }
        }

        if(dp[i][trend] != LLONG_MIN){
            return dp[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(trend == 0){
            skip = solve(nums, i+1, trend);
        }

        if(trend == 3){
            take = nums[i];
        }

        if(i + 1 < n){
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && curr < next){
                take = max(take, curr + solve(nums, i+1, 1));
            }

            else if(trend == 1){
                if(curr < next){
                    take = max(take, curr + solve(nums, i+1, 1));
                }

                else if(curr > next){
                    take = max(take, curr + solve(nums, i+1, 2));
                }
            }

            else if(trend == 2){
                if(curr > next){
                    take = max(take, curr + solve(nums, i+1, 2));
                }

                else if(curr < next){
                    take = max(take, curr + solve(nums, i+1, 3));
                }
            }

            else if(trend == 3 && curr < next){
                take = max(take, curr + solve(nums, i+1, 3));
            }
        }

        return dp[i][trend] = max(take, skip);
    }   

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<ll>(4, LLONG_MIN));

        return solve(nums, 0, 0);
    }
};