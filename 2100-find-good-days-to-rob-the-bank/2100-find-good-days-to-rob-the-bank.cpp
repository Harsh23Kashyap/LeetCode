class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) 
    {
        if(time>=sec.size())
            return {};
        
        vector<int> pre(sec.size(),0);
        vector<int> suff(sec.size(),0);
        
        for(int i=1;i<sec.size();i++)
        {
            if(sec[i]<=sec[i-1])
                pre[i]=1+pre[i-1];
        }
        
        for(int i=sec.size()-2;i>=0;i--)
        {
            if(sec[i]<=sec[i+1])
                suff[i]=1+suff[i+1];
        }
        
        

        vector<int> ans;
        for(int i=0;i<sec.size();i++)
        {
            //cout<<pre[i]<<" "<<suff[i]<<endl;
            if(suff[i]>=time and pre[i]>=time)
                ans.push_back(i);
        }
        return ans;
        
    }
};