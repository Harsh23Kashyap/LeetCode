class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int c=0;
        for(int i=0;i<strs[0].size();i++)
        {
            char prev=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(prev>strs[j][i])
                {
                    c++;
                    break;
                }
                prev=strs[j][i];
            }
        }
        return c;
    }
};