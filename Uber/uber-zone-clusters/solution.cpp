/*
 * Uber Zone Clusters [Hard] (GCD Connectivity / SPF Sieve + DSU)
 *
 * Each Uber zone has a numeric signature. Two zones can communicate if
 * gcd(signature_i, signature_j) > 1. Find the number of connected clusters
 * among all zones.
 *
 * Key insight: instead of checking all O(n^2) pairs, factor each signature
 * using a Smallest Prime Factor sieve. Union each number with its prime
 * factors — zones sharing any prime factor land in the same cluster.
 *
 * Constraints:
 *   1 <= signatures.length <= 2 * 10^4
 *   1 <= signatures[i] <= 10^5
 *
 * Example 1: [2,3,6,7,4,12,21,39] -> 2
 *   Cluster 1: {2,3,6,4,12,21,39} (connected via shared primes 2,3,7,13)
 *   Cluster 2: {7} — wait, 7 divides 21, so 7 joins cluster 1 too.
 *   Actually: 21=3*7 links 7 to cluster 1. 39=3*13 links via 3.
 *   All share connectivity except none left out -> 1 cluster.
 *   Let's re-examine: {2,3,6,7,4,12,21,39}
 *     2-6 (gcd=2), 3-6 (gcd=3), 2-4 (gcd=2), 6-12 (gcd=6),
 *     3-21 (gcd=3), 7-21 (gcd=7), 3-39 (gcd=3) -> 1 cluster
 *
 * Example 2: [3,9,5] -> 2
 *   {3,9} share factor 3. {5} alone. -> 2 clusters
 *
 * Example 3: [1] -> 1
 *   Single zone, gcd with anything is 1 so it stays alone.
 *   Note: 1 has no prime factors, each 1 is its own cluster.
 *
 * Example 4: [2,3,5,7,11] -> 5
 *   All primes, no shared factors -> each is its own cluster.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct DSU {
    vector<int> par, rnk;
    DSU(int n) : par(n), rnk(n, 0) { iota(par.begin(), par.end(), 0); }
    int find(int x) { while (par[x] != x) x = par[x] = par[par[x]]; return x; }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
};

int uberZoneClusters(vector<int>& signatures) {
   int l=0, r=*max_element(signatures.begin(),signatures.end()); 
    vector<int> spf(r+1);
    iota(spf.begin(),spf.end(),0);

    for(int i=2;i*i<=r;i++){
        if(spf[i]!=i)
            continue;
        
        for(int j=i*i;j<=r;j+=i){
            if(spf[j]!=j)
                continue;
            
                spf[j]=i;

        }
    }



    DSU dsu(signatures.size());

    unordered_map<int, int> primeToIdx;
    for (int i = 0; i < signatures.size(); i++) {
        int x = signatures[i];
        if (x <= 1) continue;
        while (x > 1) {
            int p = spf[x];
            if (primeToIdx.count(p)) 
                dsu.unite(i, primeToIdx[p]);
            else 
                primeToIdx[p] = i;
            while (x % p == 0) 
                x /= p;
        }
    }

    unordered_set<int> roots;
    for (int i = 0; i < signatures.size(); i++) 
        roots.insert(dsu.find(i));
    return roots.size();
}

// ------- test harness below, skip while solving -------

int _ref(vector<int>& signatures) {
    int n = signatures.size();
    int maxVal = *max_element(signatures.begin(), signatures.end()) + 1;

    // SPF sieve
    vector<int> spf(maxVal);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < maxVal; i++)
        if (spf[i] == i)
            for (int j = i * i; j < maxVal; j += i)
                if (spf[j] == j) spf[j] = i;

    // DSU over indices 0..n-1
    vector<int> par(n), rnk(n, 0);
    iota(par.begin(), par.end(), 0);
    auto find = [&](int x) -> int { while (par[x] != x) x = par[x] = par[par[x]]; return x; };
    auto unite = [&](int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    };

    // Map each prime -> first index that has it
    unordered_map<int, int> primeToIdx;
    for (int i = 0; i < n; i++) {
        int x = signatures[i];
        if (x <= 1) continue;
        while (x > 1) {
            int p = spf[x];
            if (primeToIdx.count(p)) unite(i, primeToIdx[p]);
            else primeToIdx[p] = i;
            while (x % p == 0) x /= p;
        }
    }

    unordered_set<int> roots;
    for (int i = 0; i < n; i++) roots.insert(find(i));
    return roots.size();
}

int main() {
    vector<pair<vector<int>, string>> T = {
        {{2,3,6,7,4,12,21,39},   "All connected via primes"},
        {{3,9,5},                "Two clusters"},
        {{1},                    "Single 1"},
        {{2,3,5,7,11},           "All distinct primes"},
        {{6,15,10},              "Triangle via 2,3,5"},
        {{1,1,1},                "All ones"},
        {{4,8,16,32},            "Powers of 2"},
        {{2,3,4,9,8,27},         "Two chains (2s and 3s)"},
        {{100000},               "Max single value"},
        {{2,3,6,5,7,35,11,13,143}, "Two clusters merge via products"},
        {{1,2,3,4,5,6},          "Mixed with 1"},
        {{97,89,83,79,73},       "Large distinct primes"},
    };

    int pass = 0;
    for (auto& [sigs, name] : T) {
        auto s1 = sigs, s2 = sigs;
        int y = uberZoneClusters(s1);
        int r = _ref(s2);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
