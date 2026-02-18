class Solution {
public:
    int uniqueLetterString(string s) 
    {
        int n = s.size();
        unordered_map<char,vector<int>> u;

        // Store indices of each character
        for (int i = 0; i < n; i++) 
            u[s[i]].push_back(i);
    

        long long result = 0;

        for (char ch='A';ch<='Z';ch++) 
        {
            if(u.find(ch)==u.end())
                continue;
            auto pos=u[ch];

            pos.insert(pos.begin(), -1);
            pos.push_back(n);

            for (int i = 1; i < pos.size() - 1; i++) {
                long long prev = pos[i - 1];
                long long curr = pos[i];
                long long next = pos[i + 1];

                result += (curr - prev) * (next - curr);
            }
        }

        return result;
    }
};
