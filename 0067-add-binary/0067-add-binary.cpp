class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string res = "";

        int sum = 0, carry = 0;

        while(i >= 0 || j >= 0){
            int d1 = (i >= 0) ? a[i] - '0' : 0;
            int d2 = (j >= 0) ? b[j] - '0' : 0;

            int sum = d1 + d2 + carry;

            res += ((sum % 2) + '0');
            carry = sum / 2;
            i--; j--;
        }

        while(i >= 0){
            int d1 = a[i] - '0';
            // int d2 = b[i] - '0';
            int sum = d1 + carry;

            res += ((sum % 2) + '0');
            carry = sum / 2;
            i--;
        }

        while(j >= 0){
            //int d1 = a[i] - '0';
            int d2 = b[j] - '0';
            int sum = d2 + carry;

            res += ((sum % 2) + '0');
            carry = sum / 2;
            j--;
        }

        if(carry){
            res += (carry + '0');
        }
        reverse(res.begin(), res.end());

        return res;
    }
};