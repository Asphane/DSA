class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;

        for(int i=0; i<n; i++){
            int total=(i+1)*(n-i);
            int oddCnt=(total+1)/2;

            ans+=arr[i]*oddCnt;
        }
        return ans;
    }
};