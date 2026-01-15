class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            int ng=st.empty() ? -1:st.top();
            mp[nums2[i]]=ng;
            st.push(nums2[i]);
        }

        vector<int> res;
        for(int nums: nums1){
            res.push_back(mp[nums]);
        }
        return res;
    }
};