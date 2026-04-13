/*
 * Shortest Way to Form String (LC 1055 variant) [Medium]
 *
 * Given two strings s (source) and t (target), return the minimum number of
 * subsequences of s that need to be concatenated to form t.
 * If it's impossible, return -1.
 *
 * A subsequence of s is a string that can be derived from s by deleting some
 * (or no) characters without changing the order of remaining characters.
 *
 * Constraints:
 *   1 <= s.length, t.length <= 10^4
 *   s and t consist of lowercase English letters
 *
 * Example 1: s="abc", t="abcbc"  -> 2  ("abc" + "bc")
 * Example 2: s="abc", t="acdbc"  -> -1  ('d' not in s)
 * Example 3: s="xyz", t="xzyxz"  -> 3  ("xz" + "y" + "xz")
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int shortestWay(string s, string t) {
    if(t.empty())
    return 0;
   unordered_map<char, vector<int>> v;
   for(int i=0;i<s.size();i++){
        v[s[i]].push_back(i);
   }
 
   for(char ch:t){
        if(v.find(ch)==v.end())
            return -1;
   }

   int i=0,j=0,c=1;
   int last=-1;
   while(j<t.size()){ 
        int ch=t[j];
        auto &vv=v[ch];
        auto idx=upper_bound(vv.begin(),vv.end(),last);
        if(idx==vv.end()){
            last=-1;
            c++;

        }
        else{
            last=*idx;
            j++;
        }
   }
   return c;


}

// ------- test harness below, skip while solving -------

int _ref(string s, string t) {
    set<char> cs(s.begin(), s.end());
    for (char c : t) if (!cs.count(c)) return -1;
    int copies = 0, i = 0;
    while (i < (int)t.size()) {
        copies++;
        int j = 0;
        while (i < (int)t.size() && j < (int)s.size()) {
            if (t[i] == s[j]) i++;
            j++;
        }
    }
    return copies;
}

int main() {
    struct TC { string s, t, name; };
    vector<TC> T = {
        {"abc",    "abcbc",     "Two copies"},
        {"abc",    "acdbc",     "Impossible char"},
        {"xyz",    "xzyxz",     "Three copies"},
        {"abc",    "abc",       "Exact match"},
        {"abc",    "a",         "Single char"},
        {"abc",    "aaa",       "Repeat first char"},
        {"abc",    "cba",       "Reverse order"},
        {"a",      "aaaa",      "Single char source"},
        {"ab",     "bababab",   "Alternating"},
        {"abcde",  "",          "Empty target"},
        {"abc",    "d",         "Impossible single"},
        {"ab",     "aabb",      "Doubled"},
    };

    int pass = 0;
    for (auto& [s, t, name] : T) {
        int y = shortestWay(s, t);
        int r = _ref(s, t);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
