class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        int maxi=0;
        if(nums.size()==1)
            return nums[0];
        for(int i=1;i<nums.size();i++)
        {
            //cout<<"index - "<<i<<endl;
            while(!pq.empty() and i-pq.top().second>k)
                pq.pop();
            
            auto it=pq.top();
            //pq.pop();
            maxi=it.first+nums[i];
           // cout<<maxi<<endl;
            pq.push({maxi,i});
            
        }
        return maxi;
        
    }
};