class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long long res = 0;

        for(int i=1; i<=n; i++){
            int bits = log2(i) + 1;

            res = (((res << bits) % M) + i) % M;
        }
        return (int)res;
    }
};