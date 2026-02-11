class Solution {
public:
    bool canTransform(string s, string res) {
        if (s.size() != res.size())
            return false;

        int n = s.size();
        int i = 0, j = 0;

        while (i < n || j < n) {

            while (i < n && s[i] == 'X') i++;
            while (j < n && res[j] == 'X') j++;

            if (i == n && j == n) return true;
            if (i == n || j == n) return false;

            if (s[i] != res[j]) return false;

            if (s[i] == 'L' && i < j) return false;
            if (s[i] == 'R' && i > j) return false;

            i++;
            j++;
        }

        return true;
    }
};
