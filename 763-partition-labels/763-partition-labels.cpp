class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> ans;
        if(s.length()==1)
        {
            ans.push_back(1);
            return ans;
        }
        unordered_map<char,int> u;
        for(int i=0;i<s.length();i++)
            u[s[i]]=i;
        
        int prev=-1;
        int end=0;
        
        //cout<<end<<endl;
        for(int i=0;i<s.length();i++)
        {
             end=max(u[s[i]],end);
            if(i==end)
            {
                ans.push_back(end-prev);
                prev=i;
            }
           
        }
        return ans;
        
    }
};