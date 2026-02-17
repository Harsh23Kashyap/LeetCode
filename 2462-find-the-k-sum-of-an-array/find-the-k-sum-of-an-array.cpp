class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long maxSum = 0;
        
        for (int &x : nums) {
            if (x > 0) maxSum += x;
            x = abs(x);
        }

        sort(nums.begin(), nums.end());

        // min heap: (removalSum, index)
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        // smallest removal sum starts with first element
        pq.push({nums[0], 0});

        long long answer = maxSum;

        while (--k) {
            auto [rem, idx] = pq.top();
            pq.pop();

            answer = maxSum - rem;

            if (idx + 1 < nums.size()) {
                // add next element
                pq.push({rem + nums[idx+1], idx+1});
                
                // replace current element with next
                pq.push({rem - nums[idx] + nums[idx+1], idx+1});
            }
        }

        return answer;
    }
};
