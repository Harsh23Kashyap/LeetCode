class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {

        unordered_set<int> ans;
        queue<long long> q;
        for(int i=1;i<=9;i++)
            q.push(i);
        
        int curr=1;
        while(!q.empty())
        {
            int sz=q.size();
            if(curr>n)
                break;
            while(sz--)
            {
                
                int top=q.front();
                //cout<<top<<endl;
                q.pop();
                if(curr==n)
                {
                    ans.insert(top);
                    continue;
                }
                
                int lastdig=top%10;
                
                
                if(lastdig-k>=0)
                    q.push(top*10+(lastdig-k));
                if(lastdig+k<10)
                    q.push(top*10+(lastdig+k));
            }
            curr++;
        }
        vector<int> res;
       for(auto it:ans)
           res.push_back(it);
        return res;
    }
};