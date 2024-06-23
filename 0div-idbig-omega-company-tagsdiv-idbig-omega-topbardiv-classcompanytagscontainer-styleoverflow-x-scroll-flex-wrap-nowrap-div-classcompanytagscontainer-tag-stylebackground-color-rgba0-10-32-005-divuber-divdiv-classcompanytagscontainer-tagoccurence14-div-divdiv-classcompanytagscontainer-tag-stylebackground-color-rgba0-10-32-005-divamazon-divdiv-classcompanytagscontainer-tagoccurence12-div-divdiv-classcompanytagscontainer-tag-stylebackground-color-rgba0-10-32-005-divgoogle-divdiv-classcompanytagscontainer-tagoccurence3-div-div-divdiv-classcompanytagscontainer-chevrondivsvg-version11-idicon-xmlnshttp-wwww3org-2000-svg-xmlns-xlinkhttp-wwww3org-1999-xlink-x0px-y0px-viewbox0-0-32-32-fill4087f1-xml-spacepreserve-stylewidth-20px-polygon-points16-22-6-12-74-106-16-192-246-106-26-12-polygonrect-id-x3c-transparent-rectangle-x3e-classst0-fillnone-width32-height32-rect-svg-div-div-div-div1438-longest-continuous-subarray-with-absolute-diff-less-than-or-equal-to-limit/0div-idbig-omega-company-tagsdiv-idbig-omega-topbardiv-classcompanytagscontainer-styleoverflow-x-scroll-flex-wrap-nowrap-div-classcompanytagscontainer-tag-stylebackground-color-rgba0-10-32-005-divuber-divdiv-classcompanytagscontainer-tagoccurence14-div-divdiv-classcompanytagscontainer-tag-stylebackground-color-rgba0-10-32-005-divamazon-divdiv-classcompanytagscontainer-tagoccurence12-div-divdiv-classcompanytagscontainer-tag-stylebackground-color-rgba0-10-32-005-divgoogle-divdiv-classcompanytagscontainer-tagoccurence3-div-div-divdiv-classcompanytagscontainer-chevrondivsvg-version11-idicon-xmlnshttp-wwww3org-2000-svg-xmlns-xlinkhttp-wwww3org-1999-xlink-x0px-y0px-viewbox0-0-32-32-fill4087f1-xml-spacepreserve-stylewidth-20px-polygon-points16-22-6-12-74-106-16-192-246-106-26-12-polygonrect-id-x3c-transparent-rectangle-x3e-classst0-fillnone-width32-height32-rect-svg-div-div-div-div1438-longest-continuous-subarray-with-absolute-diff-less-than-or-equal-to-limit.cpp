class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int minn=nums[0],maxx=nums[0];
        int low=0,high=0;
        int count=0;
        multiset<int> m;
        while(high<nums.size())
        {
            m.insert(nums[high]);
            while(abs(*m.rbegin()-*m.begin())>limit){
                m.erase(m.find(nums[low]));
                low++;
            }
            count=max(count, high-low+1);
            high++;
        }
        return count;
    }
};