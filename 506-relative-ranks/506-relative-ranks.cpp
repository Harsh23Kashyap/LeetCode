class Solution {
public:
    static bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.first > b.first);
    }
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<pair<int,int>> s;
        for(int i=0;i<score.size();i++)
            s.push_back(make_pair(score[i],i));
        sort(s.begin(),s.end(),sortbyfirst);
        vector<string> ans(score.size());
        for(int i=0;i<score.size();i++)
        {
            pair<int,int> p=s[i];
            if(i==0)
                ans[p.second]="Gold Medal";
            else if(i==1)
                ans[p.second]="Silver Medal";
            else if(i==2)
                ans[p.second]="Bronze Medal";
            else
                ans[p.second]=to_string(i+1);
            
        }
        return ans;
        
    }
};