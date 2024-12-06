class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int result = 0, sum = 0;
        unordered_set<int> bannedSet(banned.begin(), banned.end()); 
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i) == 0 && sum + i <= maxSum) { 
                sum += i;
                result++;
            }
        }
        return result;
    }
};
