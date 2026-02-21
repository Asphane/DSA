class Solution {
public:
    unordered_set<int> prime{2, 3, 5, 7, 11, 13, 17, 19};
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int num=left; num<=right; num++){
            int set_bits = __builtin_popcount(num);

            if(prime.count(set_bits)){
                res++;
            }
        }
        return res;
    }
};