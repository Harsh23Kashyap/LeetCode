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
 
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
 
        for (long long i = prefix - 1; i <= prefix + 1; i++) {
            string left=to_string(i);
            string right=left;
            if(len%2!=0)
            right.pop_back();
            reverse(right.begin(),right.end());
            string curr=left+right;
            candidates.push_back(stoll(curr));
        }

        long long best = -1;

        for (auto cand : candidates) {
            if (cand == num) continue;

            if (best == -1 or llabs(cand - num) < llabs(best - num) or 
                (llabs(cand - num) == llabs(best - num) and cand < best)) {
                best = cand;
            }
        }

        return to_string(best);
    }
};