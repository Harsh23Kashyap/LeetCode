class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int ms = s.size() / k;
        vector<int> freq(26, 0);

        for (char ch : s) 
            freq[ch - 'a']++;

        vector<char> cand;
        for (int i = 25; i >= 0; i--) 
            if (freq[i] >= k)
                cand.push_back('a' + i);

        queue<string> q;
        for (char ch : cand) 
            q.push(string(1, ch));

        string curr = "";
        while (!q.empty()) 
        {
            string it = q.front();
            q.pop();
            if (it.size() > curr.size() || (it.size() == curr.size() && it > curr)) 
                curr = it;
            for (char ch : cand) 
            {
                string ans = it + ch;
                if (ans.size() <= ms && possible(ans, s, k)) 
                    q.push(ans);
            }
        }
        return curr;
    }

    bool possible(const string &np, const string &s, int k) {
        int poss = 0, ks = 0;
        for (char ch : s) 
        {
            if (ch == np[ks]) 
            {
                ks++;
                if (ks == np.size()) 
                {
                    poss++;
                    ks = 0;
                    if (poss == k)
                        return true;
                }
            }
        }
        return false;
    }
};
