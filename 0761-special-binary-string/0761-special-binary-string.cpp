class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;

        int st = 0;
        int sum = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            sum += (s[i] == '1') ? 1 : -1;

            if(sum == 0){
                string inner = s.substr(st+1, i-st-1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                st = i+1;
            }
        }
        sort(specials.begin(), specials.end(), greater<string> ());

        string res;

        for(string &str: specials){
            res += str;
        }
        return res;
    }
};