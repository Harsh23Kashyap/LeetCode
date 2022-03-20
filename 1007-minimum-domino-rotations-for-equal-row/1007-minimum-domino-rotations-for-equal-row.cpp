class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int count=INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int curr=0;
            bool error=false;
            for(int j=0;j<tops.size();j++)
            {
                if(tops[j]==i)
                    continue;
                else if(bottoms[j]==i)
                    curr++;
                else
                {
                    error=true;
                    break;
                }
            }
            if(!error)
                count=min(curr,count);
        }
        for(int i=1;i<=6;i++)
        {
            int curr=0;
            bool error=false;
            for(int j=0;j<bottoms.size();j++)
            {
                if(bottoms[j]==i)
                    continue;
                else if(tops[j]==i)
                    curr++;
                else
                {
                    error=true;
                    break;
                }
            }
            if(!error)
                count=min(curr,count);
        }
        if(count==INT_MAX)
            return -1;
        return count;
    }
};