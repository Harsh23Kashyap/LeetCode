class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int great=INT_MIN;
        //from left
        for(int i=0;i<colors.size()-1;i++)
        {
            for(int j=i+1;j<colors.size();j++)
            {
                if(colors[j]!=colors[i])
                    great=max(great,j-i);
            }
        }
        
        
        for(int i=colors.size()-1;i>0;i--)
        {
            for(int j=i-1;j>0;j--)
            {
                if(colors[j]!=colors[i])
                    great=max(great,i-j);
            }
        }
        return great;
        
    }
};