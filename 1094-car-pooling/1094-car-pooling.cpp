class Solution {
public:
    static bool cmp(const pair<int,int> a, const pair<int,int> b)
    {
        if(a.second<b.second)
            return true;
        else if(a.second==b.second)
        {
            if(a.first<b.first)
                return true;
        }
        return false;
        
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<pair<int,int>> el;
        for(int i=0;i<trips.size();i++)
        {
            el.push_back(make_pair(trips[i][0],trips[i][1]));
            el.push_back(make_pair(-trips[i][0],trips[i][2]));
        }
        
        sort(el.begin(),el.end(),cmp);
        int total=0;
        for(auto i:el)
        {
            total+=i.first;
            if(total>capacity)
                return false;
            //cout<<i.first<< " "<<i.second<<endl;
        }
        return true;
            
        
    }
};