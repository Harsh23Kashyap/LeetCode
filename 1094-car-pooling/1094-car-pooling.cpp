class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<=b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        sort(trips.begin(),trips.end());
        
        vector<int> sized(1001,0);
        for(int i=0;i<trips.size();i++)
        {
            int start=trips[i][1];
            int end=trips[i][2];
            sized[start]+=trips[i][0];
            sized[end]-=trips[i][0];
        }
        vector<int> prefix;
        int sum=0;
        for(int i=0;i<sized.size();i++)
        {
            sum+=sized[i];
            prefix.push_back(sum);
        }
        return *max_element(prefix.begin(),prefix.end())<=capacity;
        
    }
};