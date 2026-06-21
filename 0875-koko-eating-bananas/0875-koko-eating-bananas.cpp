class Solution {
public:

    bool check(vector<int>& piles, int mid, int h){
        int ans=0;

        for(int i=0; i<piles.size(); i++){
            ans+=piles[i]/mid;

            if(piles[i]%mid){
                ans++;
            }
        }
        return ans<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());

        while(l<r){
            int mid=l+(r-l)/2;

            if(check(piles, mid, h)){
                r=mid;
            }

            else{
                l=mid+1;
            }
        }
        return r;
    }
};