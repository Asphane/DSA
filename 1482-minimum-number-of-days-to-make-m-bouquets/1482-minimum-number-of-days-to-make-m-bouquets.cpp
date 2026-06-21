class Solution {
public:

    bool check(vector<int>& bloomDay, int m, int k, int mid, int n){
        int bouq=0;
        int cnt=0;

        for(int i=0; i<n; i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }

            else{
                cnt=0;
            }

            if(cnt==k){
                bouq++;
                cnt=0;
            }
        }
        return bouq>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=0;
        int r=*max_element(bloomDay.begin(), bloomDay.end());

        if(1LL*m*k>n){
            return -1;
        }

        while(l<r){
            int mid=l+(r-l)/2;

            if(check(bloomDay, m, k, mid, n)){
                r=mid;
            }

            else{
                l=mid+1;
            }
        }
        return r;
    }
};