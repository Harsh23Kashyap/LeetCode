class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long sum = 0;
        int n = chargeTimes.size();
        deque<int> d;
        int i = 0, res = 0;
        for (int j = 0; j < n; ++j) {
            sum += runningCosts[j];
            while (!d.empty() && chargeTimes[d.back()] <= chargeTimes[j])
                d.pop_back();
            d.push_back(j);
            while (i <= j && chargeTimes[d.front()] + (j - i + 1) * sum > budget) {
                sum -= runningCosts[i];
                if (d.front() == i)
                    d.pop_front();
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res; 
    }
};