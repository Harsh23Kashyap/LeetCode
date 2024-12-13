class Solution {
    typedef pair<int,int> p;
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        
        priority_queue<p,vector<p>,greater<p>> pq;
        unordered_set<int> u;
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});
        while(!pq.empty())
        {
                auto [val,ind]=pq.top();
                
                pq.pop();
            if(u.find(ind)!=u.end())
                    continue;
                score+=val;
                if(ind-1>=0)
                    u.insert(ind-1);
                if(ind+1<nums.size())
                     u.insert(ind+1);
                
            
        }
        
        return score;
        
    }
};