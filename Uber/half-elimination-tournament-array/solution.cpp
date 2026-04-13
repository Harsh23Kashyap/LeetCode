/*
 * Half-Elimination Tournament Array [Medium]
 *
 * Given an array nums, repeatedly run rounds:
 *   - Pair adjacent values from left to right
 *   - Eliminate the higher value from each pair (keep min)
 *   - If odd count, last value advances automatically
 * Continue until one value remains.
 *
 * Return the last remaining value.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lastRemainingAfterHalfElimination(vector<int> nums) {
    // TODO: implement this function.
    return -1;
}

// ------- test harness below, skip while solving -------

int _ref(vector<int> nums) {
    while (nums.size() > 1) {
        vector<int> nxt;
        nxt.reserve((nums.size() + 1) / 2);
        for (int i = 0; i + 1 < (int)nums.size(); i += 2) {
            nxt.push_back(min(nums[i], nums[i + 1]));
        }
        if (nums.size() % 2 == 1) nxt.push_back(nums.back());
        nums.swap(nxt);
    }
    return nums[0];
}

int main() {
    struct TC {
        vector<int> nums;
        string name;
    };

    vector<TC> T = {
        {{8, 3, 5, 2}, "Even length basic"},
        {{7, 4, 9, 1, 6}, "Odd length with carry"},
        {{10}, "Single element"},
        {{5, 5, 5, 5}, "All equal values"},
        {{1, 2, 3, 4, 5, 6, 7, 8}, "Increasing sequence"},
        {{8, 7, 6, 5, 4, 3, 2, 1}, "Decreasing sequence"},
        {{-1, -5, -3, -4}, "All negative values"},
        {{1000000000, -1000000000}, "Large magnitude extremes"},
        {{9, 2, 8, 3, 7, 4, 6}, "Odd rounds multiple carries"},
        {{4, 1, 4, 1, 4, 1}, "Alternating repeats"},
        {{2, 9, 1, 8, 0, 7, -1, 6, -2}, "Mixed positives and negatives"},
        {{42, 17}, "Two elements simple pair"},
    };

    int pass = 0;
    for (auto& [nums, name] : T) {
        int y = lastRemainingAfterHalfElimination(nums);
        int r = _ref(nums);
        bool ok = (y == r);
        cout << (ok ? "\u2705" : "\u274c") << " " << name
             << "  got=" << y
             << (ok ? "" : " exp=" + to_string(r))
             << "\n";
        pass += ok;
    }

    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f")
         << " " << pass << "/" << T.size() << " passed\n";
}
