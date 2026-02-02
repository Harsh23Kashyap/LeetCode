#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = LLONG_MAX;
        long long current_sum = 0;
        
        // We need to pick 'k' subarrays. 
        // 1st is fixed at nums[0].
        // The last starts at nums[i].
        // We need to pick k-2 elements between index 1 and i-1.
        int needed = k - 2;
        
        // Use multisets to handle duplicates
        multiset<int> low; // Stores the smallest 'needed' elements
        multiset<int> high; // Stores the rest
        
        // --- Helper Function: Add value to window ---
        auto add = [&](int val) {
            // Try to put in 'low' first
            if (low.size() < needed) {
                low.insert(val);
                current_sum += val;
            } else {
                // 'low' is full. If val is smaller than the largest in 'low', swap them.
                int max_low = *low.rbegin();
                if (val < max_low) {
                    low.erase(prev(low.end())); // Remove largest from low
                    current_sum -= max_low;
                    
                    low.insert(val);            // Insert new val
                    current_sum += val;
                    
                    high.insert(max_low);       // Move old max to high
                } else {
                    high.insert(val);
                }
            }
        };

        // --- Helper Function: Remove value from window ---
        auto remove = [&](int val) {
            // Check if val is in 'high' first
            auto it_high = high.find(val);
            if (it_high != high.end()) {
                high.erase(it_high);
            } else {
                // If not in high, it must be in low
                auto it_low = low.find(val);
                if (it_low != low.end()) {
                    low.erase(it_low);
                    current_sum -= val;
                    
                    // Since we removed from 'low', we need to refill it from 'high' if possible
                    if (!high.empty()) {
                        int min_high = *high.begin();
                        high.erase(high.begin());
                        low.insert(min_high);
                        current_sum += min_high;
                    }
                }
            }
        };

        // 1. Initialize Window
        // We can pick elements starting from index 1.
        // Initially populate with indices 1 to k-2
        for (int i = 1; i <= k - 2; ++i) {
            add(nums[i]);
        }

        // 2. Slide the window
        // 'i' represents the starting index of the k-th subarray (the last cut).
        // The loop starts at k-1 because we need at least k subarrays.
        for (int i = k - 1; i < nums.size(); ++i) {
            // Before considering 'i', remove the element that is now too far away.
            // Valid window for middle elements is [i - dist, i - 1].
            // The element at 'i - dist - 1' falls out.
            int index_to_remove = i - dist - 1;
            if (index_to_remove >= 1) {
                remove(nums[index_to_remove]);
            }

            // Calculate minimum cost for this specific last index 'i'
            // Cost = nums[0] + (sum of k-2 smallest in window) + nums[i]
            long long current_total = (long long)nums[0] + current_sum + nums[i];
            ans = min(ans, current_total);

            // Add nums[i] to the window for future iterations 
            // (it becomes a candidate for a middle element when we move to i+1)
            add(nums[i]);
        }

        return ans;
    }
};