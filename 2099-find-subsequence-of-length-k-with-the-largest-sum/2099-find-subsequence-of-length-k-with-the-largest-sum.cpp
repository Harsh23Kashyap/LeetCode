class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});
        
        vector<pair<int,int>> temp;
        int i=1;
        int add=0;
        while(i++<=k)
        {
            temp.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(int i=0;i<temp.size();i++)
            ans.push_back(temp[i].second);
        
        return ans;
        
    }
};