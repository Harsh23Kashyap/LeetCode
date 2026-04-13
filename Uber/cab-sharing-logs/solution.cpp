/*
 * 4. Cab-Sharing Logs (LC 1101 variant) [Medium]
 *
 * Given n users (0-indexed) and a list of cab-sharing logs.
 * Each log is: {timestamp, userA, userB} meaning userA and userB shared a cab.
 *
 * Two users are "connected" if there is a path of shared rides between them.
 *
 * Return the earliest timestamp at which ALL n users are in one connected
 * group. Return -1 if it never happens.
 *
 * Notes:
 *   - Logs may NOT be sorted by timestamp — sort them first.
 *   - Multiple logs can share the same timestamp.
 *
 * Constraints:
 *   2 <= n <= 10^4
 *   1 <= logs.size() <= 10^5
 *   0 <= userA, userB < n, userA != userB
 *   timestamps are positive integers
 *
 * Example 1: n=4, logs=[(1,0,1),(2,1,2),(3,2,3)] -> 3
 * Example 2: n=4, logs=[(1,0,1),(2,2,3)]         -> -1
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

struct Log { int timestamp, userA, userB; };


vector<int> parent;
int find(int x){
    if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
}
int c=0;
bool unite(int a, int b){
    int pa=find(a);
    int pb=find(b);
    if(pa==pb)
        return false;
    else    
    {
        parent[pa]=pb;
        c--;

    }
    return false;

}

int earliestAllConnected(int n, vector<Log> logs) {
    c=n;
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sort(logs.begin(),logs.end(),[](auto& a, auto& b){ return a.timestamp < b.timestamp; });
    // TODO: implement

    for(int i=0;i<logs.size();i++){
        unite(logs[i].userA,logs[i].userB);
        if(c==1)
            return logs[i].timestamp;
    }
    return -1;
}







// ------- test harness below, skip while solving -------

struct DSU {
    vector<int> p, r;
    int comp;
    DSU(int n) : p(n), r(n, 0), comp(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        comp--;
    }
};

int _ref(int n, vector<Log> logs) {
    sort(logs.begin(), logs.end(), [](auto& a, auto& b){ return a.timestamp < b.timestamp; });
    DSU dsu(n);
    for (auto& l : logs) {
        dsu.unite(l.userA, l.userB);
        if (dsu.comp == 1) return l.timestamp;
    }
    return -1;
}

int main() {
    vector<tuple<int, vector<Log>, string>> T = {
        {4, {{1,0,1},{2,1,2},{3,2,3}},                          "All connect linearly"},
        {4, {{1,0,1},{2,2,3}},                                  "Two separate groups"},
        {2, {{5,0,1}},                                          "Two users one share"},
        {5, {{3,0,1},{1,2,3},{2,1,2},{4,3,4},{5,0,4}},          "Unsorted timestamps"},
        {4, {{1,0,1},{1,2,3},{2,1,2}},                          "Connect at same time"},
        {3, {},                                                  "No logs"},
        {1, {},                                                  "Single user"},
        {6, {{1,0,1},{2,2,3},{3,4,5}},                          "Three pairs never merge"},
        {4, {{1,0,1},{2,0,2},{3,0,3}},                          "Star topology"},
        {5, {{10,0,1},{20,1,2},{30,2,3},{40,3,4},{5,0,4}},      "Early shortcut"},
    };

    int pass = 0;
    for (auto& [n, logs, name] : T) {
        int y = earliestAllConnected(n, logs), r = _ref(n, logs);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
