class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        set<int> ans;
        vector<int> v;
        if(bound==0)
            return v;
        if(x==1) 
            v.push_back(1);
        else
        {
            for(int i=0;pow(x,i)<=bound;i++)
            {
                v.push_back(pow(x,i));
            }
        }
        if(y==1)
        {
            for(int i:v)
            {
                if(i+1<=bound)
                    {
                        ans.insert(i+1);
                    }
            }
        }
        else
        {
            for(int i=0;pow(y,i)<=bound;i++)
            {
                int curr=pow(y,i);
                for(int i:v)
                {
                    if(i+curr<=bound)
                    {
                        ans.insert(i+curr);
                    }
                }
            }
        }
        vector<int> another;
        for(int i:ans)
            another.push_back(i);
        return another;
        
    }
};