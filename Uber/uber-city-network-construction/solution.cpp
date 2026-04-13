/*
 * Uber City Network Construction [Medium] (MST)
 *
 * You are given n cities and a list of weighted undirected edges representing
 * possible roads between cities. Find the minimum total cost to connect all
 * cities so that every city is reachable from every other city. If it's
 * impossible, return -1.
 *
 * This is the classic Minimum Spanning Tree problem (Kruskal's / Prim's).
 *
 * Constraints:
 *   1 <= n <= 10^4
 *   0 <= edges.length <= 10^5
 *   edges[i] = {u, v, cost}
 *   1 <= cost <= 10^6
 *   0-indexed cities
 *
 * Example 1: n=4, edges={{0,1,1},{0,2,4},{1,2,2},{2,3,3}} -> 6
 *   Pick edges (0,1,1), (1,2,2), (2,3,3) = cost 6
 *
 * Example 2: n=3, edges={{0,1,5},{1,2,3}} -> 8
 *   Must use both edges to connect all 3 cities
 *
 * Example 3: n=3, edges={{0,1,2}} -> -1
 *   City 2 is unreachable
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <numeric>
#include <functional>
#include <set>
#include <unordered_set>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}
int minCostNetwork(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int,int>>> v;

    for(auto it:edges){
        v[it[0]].push_back({it[1],it[2]});
        v[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // sort(edges.begin(),edges.end());
    pq.push({0,0});
    int ans=0;
    unordered_set<int> vis;
    while(vis.size()!=n and !pq.empty()){
        auto [cost,t]=pq.top();
        pq.pop();
       if(vis.count(t))
        continue;
         ans+=cost;
        vis.insert(t);

        for(auto it:v[t]){
            if(vis.find(it.second)!=vis.end())
                continue;
            pq.push({it.second, it.first});
        }

    }
    return vis.size()==n?ans:-1;


}

// ------- test harness below, skip while solving -------

int _ref(int n, vector<vector<int>>& edges) {
    vector<int> par(n), rnk(n, 0);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x) { return par[x] == x ? x : par[x] = find(par[x]); };
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    int cost = 0, cnt = 0;
    for (auto& e : edges) {
        int a = find(e[0]), b = find(e[1]);
        if (a == b) continue;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        cost += e[2];
        if (++cnt == n - 1) break;
    }
    return cnt == n - 1 ? cost : -1;
}

int main() {
    struct TC { int n; vector<vector<int>> edges; string name; };
    vector<TC> T = {
        {4, {{0,1,1},{0,2,4},{1,2,2},{2,3,3}},           "Basic MST"},
        {3, {{0,1,5},{1,2,3}},                            "Exact edges"},
        {3, {{0,1,2}},                                    "Disconnected"},
        {1, {},                                           "Single city"},
        {2, {{0,1,7}},                                    "Two cities"},
        {2, {},                                           "Two disconnected"},
        {4, {{0,1,1},{0,2,1},{0,3,1},{1,2,1},{1,3,1},{2,3,1}}, "All same weight"},
        {5, {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}}, "Five cities"},
        {4, {{0,1,10},{0,2,6},{0,3,5},{1,2,1},{2,3,4}},  "Greedy trap"},
        {3, {{0,1,1},{0,1,2},{1,2,3},{1,2,4}},            "Duplicate edges"},
        {6, {{0,1,1},{1,2,2},{2,3,3},{3,4,4},{4,5,5},{0,5,100}}, "Chain vs shortcut"},
        {4, {{0,1,1000000},{1,2,1000000},{2,3,1000000}},  "Max weight edges"},
    };

    int pass = 0;
    for (auto& [n, edges, name] : T) {
        auto e1 = edges, e2 = edges;
        int y = minCostNetwork(n, e1);
        int r = _ref(n, e2);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
