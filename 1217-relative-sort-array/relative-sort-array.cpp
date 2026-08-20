class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        
        // Count frequency of every element
        for (int x : arr1) {
            freq[x]++;
        }
        
        vector<int> ans;
        
        // Put elements according to arr2
        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }
        
        // Put remaining elements in increasing order
        for (int x = 0; x <= 1000; x++) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }
        
        return ans;
    }
};