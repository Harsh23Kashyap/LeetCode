class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // --- Case 1: 1 Distinct Character ---
        int currentRun = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                currentRun++;
            } else {
                currentRun = 1;
            }
            maxLen = max(maxLen, currentRun);
        }

        // --- Case 2: 2 Distinct Characters ---
        // We check pairs: (a, b) avoiding c, (b, c) avoiding a, (a, c) avoiding b
        maxLen = max(maxLen, solveTwoChars(s, 'a', 'b', 'c'));
        maxLen = max(maxLen, solveTwoChars(s, 'b', 'c', 'a'));
        maxLen = max(maxLen, solveTwoChars(s, 'a', 'c', 'b'));

        // --- Case 3: 3 Distinct Characters ---
        // We need count(a) == count(b) == count(c)
        // This transforms to: diff1 = a - b, diff2 = b - c.
        // We look for same (diff1, diff2) seen previously.
        // Map key: string or combined long long for (diff1, diff2)
        // Value: first index
        
        unordered_map<string, int> map; 
        // Initial state: 0 differences at index -1
        map["0,0"] = -1;
        
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else if (s[i] == 'c') c++;

            int diff1 = a - b;
            int diff2 = b - c;
            
            // Create a unique key for the pair of differences
            string key = to_string(diff1) + "," + to_string(diff2);
            
            if (map.count(key)) {
                maxLen = max(maxLen, i - map[key]);
            } else {
                map[key] = i;
            }
        }

        return maxLen;
    }

private:
    // Helper for Case 2
    int solveTwoChars(const string& s, char target1, char target2, char forbidden) {
        int n = s.length();
        int maxLen = 0;
        unordered_map<int, int> map;
        int balance = 0;
        
        // Initialize for the start of a potential substring
        map[0] = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == forbidden) {
                // Reset everything if we hit the forbidden char
                map.clear();
                balance = 0;
                map[0] = i;
            } else {
                if (s[i] == target1) balance++;
                else if (s[i] == target2) balance--;
                
                if (map.count(balance)) {
                    maxLen = max(maxLen, i - map[balance]);
                } else {
                    map[balance] = i;
                }
            }
        }
        return maxLen;
    }
};
