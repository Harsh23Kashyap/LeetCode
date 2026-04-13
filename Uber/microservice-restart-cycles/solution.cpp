/*
 * Microservice Restart Cycles (LC 210 variant) [Medium]
 *
 * You have n microservices labeled 0 to n-1. Some services depend on others:
 * deps[i] = [a, b] means service a depends on service b (b must start before a).
 *
 * Return a valid startup order for all services. If no valid order exists
 * (circular dependency), return an empty array.
 *
 * Constraints:
 *   1 <= n <= 2000
 *   0 <= deps.length <= 5000
 *   deps[i].length == 2
 *   0 <= deps[i][0], deps[i][1] < n
 *   deps[i][0] != deps[i][1]
 *   All pairs deps[i] are unique
 *
 * Example 1: n=4, deps=[[1,0],[2,0],[3,1],[3,2]] -> [0,1,2,3] or [0,2,1,3]
 * Example 2: n=2, deps=[[1,0],[0,1]]             -> [] (cycle)
 * Example 3: n=3, deps=[]                         -> [0,1,2] (any order)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

vector<int> startupOrder(int n, vector<vector<int>>& deps) {
    vector<int> ans;
         vector<int> indegree(n,0);
         unordered_map<int,vector<int>> u;

         for(auto it:deps){
            u[it[1]].push_back(it[0]);
            indegree[it[0]]++;

         }

         queue<int> q;
         for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
             ans.push_back(i);
                q.push(i);
            }
         }

         while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto ne:u[it]){
                if(--indegree[ne]==0){
                q.push(ne);
                ans.push_back(ne);
                }
            }
         }
         if(ans.size()==n)
            return ans;
            return {};

}

// ------- test harness below, skip while solving -------

bool _validate(int n, vector<vector<int>>& deps, vector<int>& order) {
    if ((int)order.size() != n) return false;
    set<int> seen;
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
        if (order[i] < 0 || order[i] >= n || seen.count(order[i])) return false;
        seen.insert(order[i]);
        pos[order[i]] = i;
    }
    for (auto& d : deps)
        if (pos[d[1]] > pos[d[0]]) return false; // b must come before a
    return true;
}

bool _hasCycle(int n, vector<vector<int>>& deps) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto& d : deps) { adj[d[1]].push_back(d[0]); indeg[d[0]]++; }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) { q.pop(); cnt++; for (int v : adj[q.front()]) if (--indeg[v] == 0) q.push(v); }
    // fix: redo properly
    return cnt != n;
}

bool _refHasCycle(int n, vector<vector<int>>& deps) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto& d : deps) { adj[d[1]].push_back(d[0]); indeg[d[0]]++; }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    return cnt != n;
}

int main() {
    struct TC { int n; vector<vector<int>> deps; string name; bool shouldFail; };
    vector<TC> T = {
        {4, {{1,0},{2,0},{3,1},{3,2}},       "Diamond deps",       false},
        {2, {{1,0},{0,1}},                    "Simple cycle",       true},
        {3, {},                                "No deps",            false},
        {1, {},                                "Single service",     false},
        {4, {{1,0},{2,1},{3,2}},              "Linear chain",       false},
        {3, {{0,1},{1,2},{2,0}},              "Three-node cycle",   true},
        {5, {{1,0},{2,0},{3,1},{4,2},{4,3}},  "Converging deps",    false},
        {4, {{1,0},{2,0},{3,0}},              "Fan-out from 0",     false},
        {4, {{0,1},{0,2},{0,3}},              "Fan-in to 0",        false},
        {6, {{1,0},{2,1},{3,2},{4,3},{5,4}},  "Long chain",         false},
        {3, {{1,0}},                           "Partial deps",       false},
        {4, {{1,0},{2,1},{3,2},{0,3}},        "Full cycle",         true},
    };

    int pass = 0;
    for (auto& [n, deps, name, shouldFail] : T) {
        auto order = startupOrder(n, deps);
        bool ok;
        if (shouldFail) {
            ok = order.empty();
        } else {
            ok = _validate(n, deps, order);
        }
        cout << (ok ? "\u2705" : "\u274c") << " " << name;
        if (!ok) {
            if (shouldFail) cout << "  expected empty, got size=" << order.size();
            else cout << "  invalid order";
        }
        cout << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
