class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) 
    {
        int sx=startPos[0],sy=startPos[1],ex=homePos[0],ey=homePos[1];
        int ans=0;
        if(sx<ex)
        {
            for(int i=sx+1;i<=ex;i++)
                ans+=rowCosts[i];
        }
        if(sx>ex)
        {
            for(int i=sx-1;i>=ex;i--)
                ans+=rowCosts[i];
        }
        
        if(sy<ey)
        {
            for(int i=sy+1;i<=ey;i++)
                ans+=colCosts[i];    
        }
        
        if(sy>ey)
        {
            for(int i=sy-1;i>=ey;i--)
                ans+=colCosts[i];    
        }
        
        return ans;
    }
};