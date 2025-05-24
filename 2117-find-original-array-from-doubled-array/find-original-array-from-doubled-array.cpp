class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};

        unordered_map<int, int> freq;
        for (int num : changed) freq[num]++;

        vector<int> result;
        sort(changed.begin(), changed.end());

        for (int x : changed) {
            if (freq[x] == 0) continue;

            if (freq[2 * x] == 0) return {};

            result.push_back(x);
            freq[x]--;
            freq[2 * x]--;
        }

        return result;
    }
};
