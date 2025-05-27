class Solution {
public:
  const long long BASE = 256;
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long ans = 1;
        long long cur = base % MOD;
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    long long computeHash(const string &s, int length) {
        long long hashValue = 0;
        for (int i = 0; i < length; i++) {
            hashValue = (hashValue * BASE + (s[i] - 'a' + 1)) % MOD;
        }
        return hashValue;
    }

    long long rollHash(long long oldHash, char oldChar, char newChar, long long powerBase) {
        oldHash = (oldHash - ((oldChar - 'a' + 1) * powerBase) % MOD + MOD) % MOD;
        oldHash = (oldHash * BASE) % MOD;
        oldHash = (oldHash + (newChar - 'a' + 1)) % MOD;
        return oldHash;
    }

    int possible(const string &text, const string &pattern, long long powerBase) {
        int n = text.size(), m = pattern.size();
        long long patternHash = computeHash(pattern, m);
        long long textHash = computeHash(text, m);

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash) {
                // Double check actual substring to avoid collisions
                if (text.substr(i, m) == pattern) return i;
            }
            if (i < n - m) {
                textHash = rollHash(textHash, text[i], text[i + m], powerBase);
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        int m=needle.size();
        if(m>haystack.size())
        return -1;
        long long p=modPow(BASE,m-1);
        return possible(haystack,needle,p);

    }
};