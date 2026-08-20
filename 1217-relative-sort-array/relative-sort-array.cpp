class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        
        // Step 1: Elements present in arr2
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    ans.push_back(arr1[j]);
                    arr1[j] = -1;   // mark as used
                }
            }
        }
        
        // Step 2: Remaining elements
        vector<int> remaining;
        
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                remaining.push_back(arr1[i]);
            }
        }
        
        // Step 3: Sort remaining elements
        sort(remaining.begin(), remaining.end());
        
        // Step 4: Add them to answer
        for (int x : remaining) {
            ans.push_back(x);
        }
        
        return ans;
    }
};