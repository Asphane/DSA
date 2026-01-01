class Solution {
public:

    bool allZeroes(vector<int> &freq){
        return freq==vector<int>(26, 0);
    }
    
    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<int> freq(26, 0);
        vector<int> res;
        int i=0, j=0;

        for(char &ch: p){
            freq[ch-'a']++;
        }

        while(j<m){
            freq[s[j]-'a']--;

            if(j-i+1 == n){
                if(allZeroes(freq)){
                    res.push_back(i);
                }
                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};