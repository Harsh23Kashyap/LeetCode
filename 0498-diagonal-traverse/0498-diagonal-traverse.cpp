class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m=mat.size(),n=mat[0].size();
        int i=0,j=0;
        bool rev=true;
        vector<int> ans;
        
        while(true)
        {
            if(i==m-1 and j==n-1)
            {
                ans.push_back(mat[m-1][n-1]);
                break;
            }
            vector<int> temp;
            if(j<n and i==0)
            {
                for(int k=i,l=j;k<m and l>=0; k++,l--)
                    temp.push_back(mat[k][l]);
                
                if(rev)
                    reverse(temp.begin(),temp.end());
                
                ans.insert(ans.end(), temp.begin(),temp.end());
                
                j++;
                if(j==n)
                {
                    i++;
                    j--;
                }
                
            }
            else
            {
                for(int k=i,l=j;k<m and l>=0; k++,l--)
                    temp.push_back(mat[k][l]);
                
                if(rev)
                    reverse(temp.begin(),temp.end());
                
                ans.insert(ans.end(), temp.begin(),temp.end());
                
                i++;
                
            }
            rev=!rev;
            
        }
        return ans;
        
    }
};
