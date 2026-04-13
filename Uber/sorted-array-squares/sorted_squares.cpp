/*
 * 5a. Squares of a Sorted Array (LC 977) [Easy/Medium]
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   nums is sorted in non-decreasing order
 *
 * Example 1: nums = [-4,-1,0,3,10]  -> [0,1,9,16,100]
 * Example 2: nums = [-7,-3,2,3,11]  -> [4,9,9,49,121]
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;
        int i=0,j=0;
        while(i<nums.size() and nums[i]<0)
        i++,j++;
        j--; 
        while(i<nums.size() and nums[i]==0){
            ans.push_back(nums[i]);
            i++;
        }
 

        while(j>=0 or i<nums.size()){ 
            if(j>=0 and i<nums.size()){
                if(abs(nums[j])<=nums[i]){
                    ans.push_back(nums[j]*nums[j]);
                    j--;
                }
                else if(abs(nums[j])>nums[i]){
                    ans.push_back(nums[i]*nums[i]);
                    i++;
                }

            }
            else if(i<nums.size())
            {
                 ans.push_back(nums[i]*nums[i]);
                    i++;
            }
            else if (j>=0){
                ans.push_back(nums[j]*nums[j]);
                    j--;
            }
        } 
        return ans;
}

// ------- test harness below, skip while solving -------

vector<int> _ref(vector<int> nums) {
    for (auto& x : nums) x = x * x;
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<pair<vector<int>, string>> T = {
        {{-4,-1,0,3,10},        "Mixed neg/pos"},
        {{-7,-3,2,3,11},        "Mixed with dup squares"},
        {{-5,-3,-2,-1},          "All negative"},
        {{1,2,3,4,5},            "All positive"},
        {{0},                    "Single zero"},
        {{-1,1},                 "Symmetric"},
        {{0,0,0},                "All zeros"},
        {{-10000,10000},         "Boundary values"},
        {{-3,-2,-1,0,1,2,3},    "Symmetric range"},
        {{-1},                   "Single negative"},
    };

    int pass = 0;
    for (auto& [nums, name] : T) {
        auto yours = sortedSquares(nums);
        auto ref = _ref(nums);
        bool ok = (yours == ref);
        cout << (ok ? "\u2705" : "\u274c") << " " << name;
        if (!ok) {
            cout << "  got=[";
            for (int i = 0; i < (int)yours.size(); i++) cout << yours[i] << (i+1<(int)yours.size()?",":"");
            cout << "] exp=[";
            for (int i = 0; i < (int)ref.size(); i++) cout << ref[i] << (i+1<(int)ref.size()?",":"");
            cout << "]";
        }
        cout << "\n";
        pass += ok;
    }
    cout << "\n" << (pass == (int)T.size() ? "\xf0\x9f\x8e\x89" : "\xe2\x9a\xa0\xef\xb8\x8f") << " " << pass << "/" << T.size() << " passed\n";
}
