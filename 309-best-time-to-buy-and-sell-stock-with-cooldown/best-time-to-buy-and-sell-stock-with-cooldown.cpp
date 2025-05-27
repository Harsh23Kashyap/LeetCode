#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2, -1));
        return dfs(0, 1, prices);
    }

    int dfs(int i, int buy, vector<int>& prices) {
        if (i >= prices.size()) return 0;
        if (memo[i][buy] != -1) return memo[i][buy];

        if (buy) {
            // Option 1: buy at i, pay prices[i], next state no buy (holding stock)
            int buyStock = -prices[i] + dfs(i + 1, 0, prices);
            // Option 2: skip buying today
            int skip = dfs(i + 1, 1, prices);
            return memo[i][buy] = max(buyStock, skip);
        } else {
            // Option 1: sell at i, gain prices[i], cooldown next day (i+2)
            int sellStock = prices[i] + dfs(i + 2, 1, prices);
            // Option 2: skip selling today
            int skip = dfs(i + 1, 0, prices);
            return memo[i][buy] = max(sellStock, skip);
        }
    }
};
