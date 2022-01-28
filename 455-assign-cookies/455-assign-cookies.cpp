class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {

        int g1=g.size();
        int s1=s.size();
        
        sort(g.begin(),g.end());   
        sort(s.begin(),s.end()); 
        
        int count=0,j=0,i=0;
        while(i<g1 && j<s1)
        {
            if(g[i]<=s[j])
            {
                count++;
                i++;
                j++;

            }

            else 
                j++;
        }
    return count;
    }
};