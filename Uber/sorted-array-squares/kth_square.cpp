/*
 * 5b. K-th Smallest Square from Sorted Array [Medium/Hard]
 *
 * Given an integer array nums sorted in non-decreasing order and an integer k,
 * return the k-th smallest squared element in O(log n) time without building
 * the full squared array.
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   nums is sorted in non-decreasing order
 *   1 <= k <= nums.length
 *
 * Example 1: nums = [-4,-1,0,3,10], k=1 -> 0
 * Example 2: nums = [-4,-1,0,3,10], k=3 -> 9
 * Example 3: nums = [-7,-3,2,3,11], k=2 -> 9
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int kthSmallestSquare(vector<int>& nums, int k) {
    int n=nums.size();
    long long l=0,h=max(1ll*nums[0]*nums[0],1ll*nums.back()*nums.back());
    int res=nums[0];
    while(l<=h){
        int m=l+(h-l)/2;
        int ms=(int)sqrt(m);

        int r=upper_bound(nums.begin(),nums.end(),ms)-nums.begin();
        int lo=lower_bound(nums.begin(),nums.end(),-ms)-nums.begin();
        int c=r-lo;
        if(c==k){
            return ms*ms;
        }
        else if(c>=k){
            h=m-1;
            res=ms*ms;
        }
        else{
            l=m+1;
        }

        
    }
    return res;
}

// ------- test harness below, skip while solving -------

int _ref(vector<int> nums, int k) {
    for (auto& x : nums) x = x * x;
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}

int main() {
    struct TC { vector<int> nums; int k; string name; };
    vector<TC> T = {
        {{-4,-1,0,3,10},      1,  "k=1 smallest"},
        {{-4,-1,0,3,10},      3,  "k=3 middle"},
        {{-4,-1,0,3,10},      5,  "k=n largest"},
        {{-7,-3,2,3,11},      2,  "Dup squares k=2"},
        {{-5,-3,-2,-1},        1,  "All neg k=1"},
        {{-5,-3,-2,-1},        4,  "All neg k=n"},
        {{1,2,3,4,5},          3,  "All pos k=3"},
        {{0},                  1,  "Single zero"},
        {{-1,1},               1,  "Symmetric k=1"},
        {{-1,1},               2,  "Symmetric k=2"},
        {{-3,-2,-1,0,1,2,3},  4,  "Symmetric range k=4"},
        {{-10000,10000},       1,  "Boundary k=1"},
        {{-1},                 1,  "Single neg"},
    };

    int pass = 0;
    for (auto& [nums, k, name] : T) {
        int y = kthSmallestSquare(nums, k);
        int r = _ref(nums, k);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  got=" << y << (ok ? "" : " exp=" + to_string(r)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
