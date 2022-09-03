class Solution {
public:
    int ans;
    void backtrack(int pos, vector<int>& tasks, vector<int>& buckets,int st)
    {
       // cout<<pos<<endl;
        if(pos == tasks.size())
        {
            if(buckets.size()<ans)
                ans=buckets.size();
            return;
        }
        if(buckets.size()>ans)
            return;
        for(int b = 0; b < buckets.size(); b++)
        {
            if(buckets[b]+tasks[pos]<=st)
            {
                buckets[b]+=tasks[pos];
                backtrack(pos+1,tasks,buckets,st);
                buckets[b]-=tasks[pos];
            }
        }
        buckets.push_back(tasks[pos]);
        backtrack(pos+1,tasks,buckets,st);
        buckets.pop_back();
    }
    
    int minSessions(vector<int>& tasks, int st) 
    {
        sort(tasks.begin(),tasks.end(),greater<int>());
        ans = INT_MAX;
        vector<int> buckets;
        backtrack(0, tasks, buckets,st);
        return ans;
        
    }
};