class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        for(int i=0;i<costs.size();i++)
        {
            int diff=costs[i][0]-costs[i][1];
            costs[i].insert(costs[i].begin(),diff);
        }
        
        sort(costs.begin(),costs.end());
        //reverse(costs.begin(),costs.end());
        
        int sum=0;
        for(int i=0;i<costs.size();i++)
        {
            if(i<costs.size()/2)
            {
                sum+=costs[i][1];
            }
            else
                sum+=costs[i][2];
        }
        
        
        return sum;
    }
};