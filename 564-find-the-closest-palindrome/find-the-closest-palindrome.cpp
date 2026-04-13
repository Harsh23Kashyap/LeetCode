class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1){
            if(n=="0")
                return "1";
            return to_string(n[0]-'0'-1);
        }
        long long num = stoll(n);
        int len = n.size();

        // Edge candidates
        vector<long long> candidates;
        candidates.push_back(stoll(string(len - 1, '9')));
        candidates.push_back(stoll(string(len , '9')));
        candidates.push_back(stoll("1" + string(len - 1, '0') + "1"));
         candidates.push_back(stoll("1" + string(len - 2, '0') + "1"));

        // Get prefix
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate 3 palindromes from prefix-1, prefix, prefix+1
        for (long long i = prefix - 1; i <= prefix + 1; i++) {
            string left = to_string(i);
            string right = left;

            if (len % 2 == 1) right.pop_back(); // remove middle for odd

            reverse(right.begin(), right.end());
            string pal = left + right;

            candidates.push_back(stoll(pal));
        }

        long long best = -1;

        for (auto cand : candidates) {
            if (cand == num) continue;

            if (best == -1 ||
                llabs(cand - num) < llabs(best - num) ||
                (llabs(cand - num) == llabs(best - num) && cand < best)) {
                best = cand;
            }
        }

        return to_string(best);
    }
};