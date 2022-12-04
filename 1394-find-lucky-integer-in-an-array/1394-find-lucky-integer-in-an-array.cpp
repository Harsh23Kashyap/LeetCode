class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        map<int,int> u;
        for(int i:arr)
            u[i]++;
        
        int ans=-1;
        for(auto it: u)
        {
            if(it.first==it.second)
            {
                ans= it.first;
            }
        }
        
        return ans;
        
    }
};