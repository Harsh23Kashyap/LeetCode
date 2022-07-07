class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {

        deque<int> d;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            //cout<<i<<endl;
            while(!d.empty() and d.front()<=(i-k))
                d.pop_front();
            while(!d.empty() and nums[d.back()]<=nums[i])
                d.pop_back();
            //cout<<"s"<<d.size();
            d.push_back(i);
            if(i+1>=k)
                ans.push_back(nums[d.front()]);
                
        }
        return ans;
        
    }
};