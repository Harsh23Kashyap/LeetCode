class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int begin;;
        int end;
        vector<vector <int>> ans;
        vector <int> curr;
        begin=intervals[0][0];
        end=intervals[0][1];
        curr.push_back(begin);
        for(int i=1;i<intervals.size();i++)
        {
            if(end>=intervals[i][0])
            {
                end=max(intervals[i][1],end);
                
            }
            else
            {
                curr.push_back(end);
                ans.push_back(curr);
                curr.clear();
                curr.push_back(intervals[i][0]);
                end=intervals[i][1];
            }
        }
        curr.push_back(end);
                ans.push_back(curr);
        return ans;
        
    }
};