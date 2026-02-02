class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> Kmini;
        set<P> rem;
        ll sum = 0;

        int i = 1;
        while(i - dist < 1){
            Kmini.insert({nums[i], i});
            sum += nums[i];

            if(Kmini.size() > k-1){
                P temp = *Kmini.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                Kmini.erase(temp);
            }
            i++;
        }

        ll res = LONG_MAX;
        while(i < n){
            Kmini.insert({nums[i], i});
            sum += nums[i];

            if(Kmini.size() > k-1){
                P temp = *Kmini.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                Kmini.erase(temp);
            }
            res = min(res, sum);

            P remove = {nums[i - dist], i - dist};
            if(Kmini.count(remove)){
                Kmini.erase(remove);
                sum -= remove.first;
            
                if(!rem.empty()){
                    P temp = *rem.begin();
                    sum += temp.first;
                    Kmini.insert(temp);
                    rem.erase(temp);
                }
            }

            else{
                rem.erase(remove);
            }
            i++;
        }
        return nums[0] + res;
    }
};