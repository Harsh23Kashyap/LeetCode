class Solution {
public:
    bool backtrack(vector<int>& jobs, vector<int>& workers, int idx, int limit) {
        if (idx == jobs.size())
            return true;

        int currJob = jobs[idx];

        for (int i = 0; i < workers.size(); i++) {

            if (workers[i] + currJob <= limit) {

                workers[i] += currJob;

                if (backtrack(jobs, workers, idx + 1, limit))
                    return true;

                workers[i] -= currJob;
            }

            // pruning
            if (workers[i] == 0 || workers[i] + currJob == limit)
                break;
        }

        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());

        int l = *max_element(jobs.begin(), jobs.end());
        int r = accumulate(jobs.begin(), jobs.end(), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;

            vector<int> workers(k, 0);

            if (backtrack(jobs, workers, 0, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
