class Solution {
public:

    long long cnt = 0;
    
    void merge(vector<int>& nums, int l, int r, int m){
        int n1 = m-l+1;
        int n2 = r-m;
        
        vector<int>L(n1);
        vector<int>R(n2);
        int k = l;
        
        for(int i=0; i<n1; i++){
            L[i] = nums[k];
            k++;
        }
        
        for(int i=0; i<n2; i++){
            R[i] = nums[k];
            k++;
        }
        
        int j=0;

        for(int i=0; i<n1; i++){
            while(j<n2 && L[i] > 2LL * R[j]){
                j++;
            }
            cnt += j;
        }

        k = l;
        int i=0;
        j=0;
        
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                nums[k] = L[i];
                i++;
            }
            
            else{
                nums[k] = R[j];
                j++; 
            }
            k++;
        }
        
        while(i < n1){
            nums[k] = L[i];
            i++;
            k++;
        }
        
        while(j < n2){
            nums[k] = R[j];
            j++;
            k++;
        }
        
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        // code here
        if(l >= r){
            return;
        }
        
        int m = l + (r-l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        
        merge(nums, l, r, m);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return cnt;
    }
};