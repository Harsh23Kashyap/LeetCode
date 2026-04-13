/*
 * Verifying Text Order Rule [Medium]
 *
 * Given:
 *   - order: a string with distinct lowercase letters defining allowed order
 *   - text:  a lowercase string
 *
 * Return true if text respects the order rule:
 *   1) Only characters in text that appear in order are considered.
 *   2) Their rank sequence according to order must be non-decreasing.
 *   3) Characters not present in order are ignored.
 *
 * Example 1: order="abc", text="aaxbbcc" -> true
 * Example 2: order="abc", text="abca"    -> false
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool verifyTextOrderRule(string order, string text) {
    unordered_set<char> orderSet(order.begin(), order.end());
    int l = 0, r = 0;
    while (r < text.size()) {
        // Move r forward until a character in order is found
        while (r < text.size() && orderSet.find(text[r]) == orderSet.end()) r++;
        if (r == text.size()) break;

        // Compare with the current order character at l
        while (l < order.size() && (r == text.size() || order[l] != text[r])) l++;

        if (l == order.size()) return false;

        // Found matching order[l] == text[r]
        l++;
        r++;
    }
    return true;
}
// bool verifyTextOrderRule(string order, string text) {
//     unordered_map<char,int> u;
//     for(int i=0;i<order.size();i++)
//         u[order[i]]=i;
    
    
//     int l=0,r=0;
//     while(r<text.size())
//     {
//         if(u.find(text[r])==u.end()){
//             r++;
//             continue;
//         }
//         if(u[text[r]]<l)
//             return false;
//         l=u[text[r]];
//         r++;
//     }
//     return true;
// }


// ------- test harness below, skip while solving -------

bool _ref(string order, string text) {
    vector<int> rank(26, -1);
    for (int i = 0; i < (int)order.size(); i++) {
        rank[order[i] - 'a'] = i;
    }

    int last = -1;
    for (char ch : text) {
        int r = rank[ch - 'a'];
        if (r == -1) continue;
        if (r < last) return false;
        last = r;
    }
    return true;
}

int main() {
    struct TC {
        string order, text, name;
    };

    vector<TC> T = {
        {"abc", "aaxbbcc", "Grouped valid sequence"},
        {"abc", "abca", "Backtrack to earlier rank"},
        {"hlo", "hello", "Ignored chars still valid"},
        {"hlo", "ohl", "Strict decrease"},
        {"xyz", "aaaa", "No constrained chars in text"},
        {"z", "zzzzz", "Single constrained letter"},
        {"z", "azbzcz", "Mixed with ignored letters"},
        {"qwerty", "qqwweerrttyy", "Repeated monotonic ranks"},
        {"qwerty", "qweq", "Rank decreases at end"},
        {"abc", "", "Empty text"},
        {"mno", "nnom", "Decrease after increase"},
        {"abcd", "aabbccdd", "Perfect non-decreasing order"},
    };

    int pass = 0;
    for (auto& [order, text, name] : T) {
        bool y = verifyTextOrderRule(order, text);
        bool r = _ref(order, text);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name
             << "  got=" << (y ? "true" : "false")
             << (ok ? "" : string(" exp=") + (r ? "true" : "false"))
             << "\n";
        pass += ok;
    }

    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f")
         << " " << pass << "/" << T.size() << " passed\n";
}
