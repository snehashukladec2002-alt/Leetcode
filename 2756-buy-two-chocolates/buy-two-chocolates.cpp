class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int n = prices.size();
        int minSum = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                int sum = prices[i] + prices[j];
                
                if(sum <= money) {
                    minSum = min(minSum, sum);
                }
            }
        }
        
        // No pair can be bought
        if(minSum == INT_MAX)
            return money;
        
        return money - minSum;
    }
};