class Solution {
public:
    int minRefuelStops(int t, int f, vector<vector<int>>& st) 
    {
        priority_queue<int> pq;
        int c=0;
        int pos=0;
        for(int i=0;i<st.size();i++)
        {
           
            if(st[i][0]-pos>f)
            {
                while(!pq.empty() and st[i][0]-pos>f)
                {
                    f+=pq.top();
                    pq.pop();
                    c++;
                }
                if(pq.empty() and   st[i][0]-pos>f)
                    return -1;
            }
            f-=(st[i][0]-pos);
            pos=st[i][0];
            pq.push(st[i][1]);
        }
        while(!pq.empty() and t-pos>f)
        {
            f+=pq.top();
            pq.pop();
            c++;
        }
        if(pq.empty() and   t-pos>f)
            return -1;
        return c;
        
    }
};