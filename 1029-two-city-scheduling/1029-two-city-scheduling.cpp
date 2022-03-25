class Solution {
public:
    static bool cmp ( vector <int> &a, vector <int> &b )
    {
        if( a[0] - a[1]  < b[0] - b[1]) 
            return true; 
        return false;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
//         for(int i=0;i<costs.size();i++)
//         {
//             int diff=costs[i][0]-costs[i][1];
//             costs[i].insert(costs[i].begin(),diff);
//         }
        
        sort(costs.begin(),costs.end(),cmp);
        //reverse(costs.begin(),costs.end());
        
        int sum=0;
        for(int i=0;i<costs.size();i++)
        {
            if(i<costs.size()/2)
            {
                sum+=costs[i][0];
            }
            else
                sum+=costs[i][1];
        }
        
        
        return sum;
    }
};