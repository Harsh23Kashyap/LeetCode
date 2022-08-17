class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        deque<int> d;
        d.push_back(0);
        for(int i=1;i<nums.size();i++)
        {
            while(i-k>d.front())
                d.pop_front();
            nums[i]+=nums[d.front()];
            while(!d.empty() and nums[d.back()]<nums[i])
                d.pop_back();
            d.push_back(i);
            
            //maxi=max(maxi,curr);
        }
        return nums[nums.size()-1];
        
    }
};