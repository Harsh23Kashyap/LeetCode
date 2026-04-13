/*
 * 13. Optimal Binary Search Tree [Hard]
 *
 * Given n sorted keys and their search frequencies, construct a BST that
 * minimizes the total weighted search cost.
 *
 * The cost of searching a key at depth d (root = depth 1) is freq[i] * d.
 * Total cost = sum of freq[i] * depth(key[i]) for all keys.
 *
 * Return the minimum total search cost.
 *
 * This is the classic Knuth OBST problem, solvable with O(n^3) DP.
 *
 * Constraints:
 *   1 <= n <= 500
 *   1 <= freq[i] <= 10^4
 *   keys are sorted in increasing order
 *
 * Example 1: keys=[10,12,20], freq=[34,8,50]  -> 142
 *   Optimal tree: 20 as root, 10 as left child, 12 as right child of 10
 *   Cost: 50*1 + 34*2 + 8*3 = 142
 *
 * Example 2: keys=[10,12], freq=[34,50]  -> 118
 *   Optimal tree: 12 as root, 10 as left child
 *   Cost: 50*1 + 34*2 = 118
 *
 * Example 3: keys=[1,2,3,4], freq=[1,1,1,1]  -> 8
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
 vector<int> ps;
int pass(int l, int r, vector<vector<int>> &dp,vector<int>& freq ){
    if(l>r) return 0;
    if(l==r) return freq[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    

    int ans=INT_MAX;
    int sum=ps[r]-((l>0)?ps[l-1]:0);

    for(int k=l;k<=r;k++){
        ans=min(ans, sum+pass(l,k-1,dp,freq)+pass(k+1,r,dp,freq));
        
    }
    return dp[l][r]=ans;

}
int optimalBST(vector<int>& keys, vector<int>& freq) {
    int n=keys.size();
    ps.clear();
   int s=0;
   for(auto it:freq){
    s+=it;
    ps.push_back(s);
   }


   vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
   return pass(0,n-1,dp, freq);
}

// ------- test harness below, skip while solving -------

int _ref(vector<int>& keys, vector<int>& freq) {
    int n = freq.size();
    // dp[i][j] = min cost BST for keys[i..j]
    // prefix[i][j] = sum of freq[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> psum(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        psum[i][i] = freq[i];
        dp[i][i] = freq[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            psum[i][j] = psum[i][j-1] + freq[j];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int cost = psum[i][j];
                if (r > i) cost += dp[i][r-1];
                if (r < j) cost += dp[r+1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    struct TC { vector<int> keys, freq; string name; };
    vector<TC> T = {
        {{10,12,20},         {34,8,50},          "Three keys"},
        {{10,12},            {34,50},             "Two keys"},
        {{1,2,3,4},          {1,1,1,1},           "Uniform freq"},
        {{5},                {10},                "Single key"},
        {{1,2,3},            {1,100,1},           "Heavy middle"},
        {{1,2,3},            {100,1,1},           "Heavy left"},
        {{1,2,3},            {1,1,100},           "Heavy right"},
        {{1,2,3,4,5},        {5,4,3,2,1},         "Decreasing freq"},
        {{1,2,3,4,5},        {1,2,3,4,5},         "Increasing freq"},
        {{10,20,30,40},      {4,2,6,3},           "Mixed freq"},
        {{1,2,3,4,5,6,7},   {1,1,1,1,1,1,1},     "Seven uniform"},
        {{1,2},              {1,1},               "Two equal"},
    };

    int pass = 0;
    for (auto& [keys, freq, name] : T) {
        int y = optimalBST(keys, freq);
        int r = _ref(keys, freq);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
