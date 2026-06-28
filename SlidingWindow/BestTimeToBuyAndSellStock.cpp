#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(int sell : prices)
        {
            profit = max(profit, sell - buy);
            buy = min(buy, sell);
        }
        return profit;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)