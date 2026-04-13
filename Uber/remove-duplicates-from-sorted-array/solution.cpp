/*
 * 26. Remove Duplicates from Sorted Array [Easy]
 *
 * Given an integer array nums sorted in non-decreasing order, remove the
 * duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * Return the number of unique elements k.
 *
 * Constraints:
 *   1 <= nums.length <= 3 * 10^4
 *   -100 <= nums[i] <= 100
 *   nums is sorted in non-decreasing order.
 *
 * Example 1: nums = [1,1,2]           -> k=2, nums = [1,2,_]
 * Example 2: nums = [0,0,1,1,1,2,2,3,3,4] -> k=5, nums = [0,1,2,3,4,_,_,_,_,_]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int removeDuplicates(vector<int>& arr) {
      int i=0,j=1;
        while(i<arr.size() and j<arr.size()){
            if(arr[i]==arr[j])
            {
                j++;
            }
            else{
                i++;
                arr[i]=arr[j];
            }
        }
        return i+1;
    return 0;
}

// ------- everything below is test harness, skip while solving -------

int _ref(vector<int>& a) {
    int k = 1;
    for (int i = 1; i < (int)a.size(); i++)
        if (a[i] != a[i-1]) a[k++] = a[i];
    return k;
}

int main() {
    vector<pair<vector<int>, string>> T = {
        {{1,1,2},                                "Example 1"},
        {{0,0,1,1,1,2,2,3,3,4},                 "Example 2"},
        {{1},                                    "Single"},
        {{-100,-100,-100},                       "All same"},
        {{1,2,3,4,5},                            "Already unique"},
        {{1,1},                                  "Two same"},
        {{1,2},                                  "Two diff"},
        {{-100,100},                             "Min/Max"},
        {{-100,-100,0,0,100,100},                "Boundary dups"},
        {{1,1,1,2,2,3,3,3,3,4,5,5,6,7,7,7,8,9,9,10}, "Larger"},
    };
    int pass = 0;
    for (auto& [nums, name] : T) {
        auto a = nums, b = nums;
        int yk = removeDuplicates(a), rk = _ref(b);
        bool ok = (yk == rk);
        for (int i = 0; ok && i < rk; i++) ok = (a[i] == b[i]);
        cout << (ok ? "\u2705" : "\u274c") << " " << name << "  k=" << yk << (ok ? "" : " expected=" + to_string(rk)) << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
