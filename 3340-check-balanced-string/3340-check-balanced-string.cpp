class Solution {
public:
    bool isBalanced(string num) {
        int n=num.size();

        int odd_sum=0, even_sum=0;
        int i=0;
        while(i<n){
            int x=num[i]-'0';
            if(i%2==0){
                even_sum+=x;
            }

            else{
                odd_sum+=x;
            }
            i++;
        }
        return even_sum==odd_sum;
    }
};