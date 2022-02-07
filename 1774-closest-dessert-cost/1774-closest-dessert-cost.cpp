class Solution {
public:
    set<int> s;
    void make(vector<int>& toppingCosts, int i, int currcost,int target)
    {
        if(i==toppingCosts.size())
        {
            s.insert(currcost);
            return;
            
        }
        if(currcost==target)
        {
            s.insert(currcost);
            return;
        }
        else
        {
            s.insert(currcost);
            //dont take this one
            make(toppingCosts,i+1,currcost,target);
            //take 1
             make(toppingCosts,i+1,currcost+toppingCosts[i],target);
            //take 2
             make(toppingCosts,i+1,currcost+2*toppingCosts[i],target);
        }
        
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        for(int i=0;i<baseCosts.size();i++)
        {
            //if(baseCosts[i]>target) continue;
            if(baseCosts[i]==target) return target;
            make(toppingCosts,0,baseCosts[i],target);
        }
        int best=INT_MAX;
        int ans=0;
        for(auto i:s)
        {
            if(abs(target-i)<best)
            {
                best=abs(target-i);
                ans=i;
            }
            else if(target-i==0)
                return target;
        }
        return ans;
        
    }
};