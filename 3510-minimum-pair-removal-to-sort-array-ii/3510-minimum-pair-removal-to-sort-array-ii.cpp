class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();

        set<pair<ll, int>> minSet;
        vector<ll> temp(n);
        vector<int> prev(n);
        vector<int> next(n);

        int bad=0;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                bad++;
            }
            minSet.insert({nums[i] + nums[i+1], i});
        }

        for(int i=0; i<n; i++){
            temp[i] = nums[i];
            prev[i] = i-1;
            next[i] = i+1;
        }

        int operations=0;

        while(bad > 0){
            int first = minSet.begin()->second;
            int sec = next[first];

            int first_left = prev[first];
            int sec_right = next[sec];

            minSet.erase(minSet.begin());

            if(temp[first] > temp[sec]) bad--;

            if(first_left >= 0){
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[sec]){
                    bad--;
                }

                else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[sec]){
                    bad++;
                }
            }

            if(sec_right < n){
                if(temp[sec_right] < temp[sec] && temp[sec_right] >= temp[first] + temp[sec]){
                    bad--;
                }

                else if(temp[sec_right] >= temp[sec] && temp[sec_right] < temp[first] + temp[sec]){
                    bad++;
                }
            }

            if(first_left >= 0){
                minSet.erase({temp[first_left] + temp[first], first_left});
                minSet.insert({temp[first_left] + temp[first] + temp[sec], first_left});
            }

            if(sec_right < n){
                minSet.erase({temp[sec_right] + temp[sec], sec});
                minSet.insert({temp[sec_right] + temp[first] + temp[sec], first});
                prev[sec_right] = first;
            }

            next[first] = sec_right;
            temp[first] += temp[sec];

            operations++;
        }
        return operations;
    }
};