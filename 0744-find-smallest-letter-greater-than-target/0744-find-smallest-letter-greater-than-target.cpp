class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int ans=INT_MAX;
        int res=letters[0];

        for(int i=0; i<n; i++){
            if(letters[i] > target && letters[i]-target < ans){
                ans=letters[i]-target;
                res=letters[i];
            }
        }
        return res;
    }
};