class Solution {
public:
    static bool sorted(vector<int>&f, vector<int>& s)
    {
        if(f[0]<s[0])
            return true;
        else if(f[0]==s[0])
        {
            if(f[1]>=s[1])
                return true;
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),sorted);
        
        int s=intervals[0][0];
        int e=intervals[0][1];
        int cnt=1;
        for(int i=1;i<intervals.size();i++)
        {
            
            if(intervals[i][1]>e)
            {
                cnt++;
                s=intervals[i][0];
                e=intervals[i][1];
            }
                
                
        }
        return cnt;
    }
};