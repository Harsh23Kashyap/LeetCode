class Solution {
public:
    int reverseDegree(string s) {
                long long total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reverse_pos = 26 - (s[i] - 'a');
            int string_pos = i + 1;
            total += (long long)reverse_pos * string_pos;
        }
        return (int)total; 
    }
};