class Solution {
public:
    string longestPrefix(string s) {
        long long base = 31;
        long long mod = 1e9 + 7;

        long long prefix_hash = 0;
        long long suffix_hash = 0;
        long long power = 1;

        int n = s.size();
        int max_len = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            int left_val = s[i] - 'a' + 1;
            int right_val = s[n - 1 - i] - 'a' + 1;

            prefix_hash = (prefix_hash * base + left_val) % mod;
 
            suffix_hash = (suffix_hash + right_val * power) % mod;
 
            power = (power * base) % mod;
 
            if (prefix_hash == suffix_hash ) {
                // if(s.substr(0,i+1)==s.substr(n-1-i))
                    max_len = i + 1;
            }
        }

        return s.substr(0, max_len);
    }
};