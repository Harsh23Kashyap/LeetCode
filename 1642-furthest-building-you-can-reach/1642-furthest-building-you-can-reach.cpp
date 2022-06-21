class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int,vector<int>,greater<int> > pq;
        int i;
        for(i=0;i<heights.size()-1;i++)
        {
            if(heights[i+1]<=heights[i])
                continue;
            else
            {
                pq.push(heights[i+1]-heights[i]);
                if(pq.size()>ladders)
                {
                    if(pq.top()>bricks)
                        break;
                    else
                    {
                        bricks-=pq.top();
                        pq.pop();
                    }
                }
            }
        }
        return i;
        
    }
};