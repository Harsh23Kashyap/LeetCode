class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
                nums[i]*=2;
            
            cout<<nums[i]<<" ";
        }
        
        int diff=INT_MAX;
        int mini=*min_element(nums.begin(),nums.end());
        priority_queue<int> pq;
        
        for(int i:nums)
            pq.push(i);
        
        while(!pq.empty() && pq.top()%2==0)
        {
            int maxval = pq.top();
            pq.pop();
            diff = min(diff,maxval-mini);
            mini = min(mini,maxval/2);
            pq.push(maxval/2);
        }
        return min(diff,pq.top()-mini);
    }
};