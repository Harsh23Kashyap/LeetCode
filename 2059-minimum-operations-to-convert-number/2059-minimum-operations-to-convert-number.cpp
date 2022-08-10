class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        queue<int> q;
        int ans=0;
        q.push(start);
        vector<bool> vis(1001,false);
        while(!q.empty())
        {
            
            int sz=q.size();
            while(sz--)
            {
                auto it=q.front();
                //cout<<it<<endl;
                q.pop();
                if(it==goal)
                    return ans;
                //cout<<"h"<<endl;
                if(it>1000 or it<0)
                    continue;
                if(vis[it])
                    continue;
                vis[it]=true;
                for(int i=0;i<nums.size();i++)
                {
                    q.push(nums[i]+it);
                    q.push(-nums[i]+it);
                    q.push(nums[i]^it);
                }
                
                
                
            }
            ans++;
            
        }
        return -1;
        
        
    }
};