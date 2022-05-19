class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& lip,int r, int c)
    {
         if(lip[r][c]!=-1)
             return lip[r][c];
        int row=matrix.size();
        int col= matrix[0].size();
        
        vector<vector<int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        //cout<<r<<" "<<c<<endl;
        int maxi=0;
        for(int i=0;i<dir.size();i++)
        {
            int currx=r+dir[i][0];
            int curry=c+dir[i][1];
            if(currx>=0 and curry>=0 and currx<row and curry<col)
            {
                    if(matrix[r][c]<matrix[currx][curry])
                    {
                        //cout<<"Inside"<<endl;
                        maxi=max(maxi,dfs(matrix,lip,currx,curry)+1);
                        //cout<<currx<<" "<<curry<<" ->"<<lip[currx][curry]<<endl;
                    }
            }
        }
        lip[r][c]=maxi;
        return maxi;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int row=matrix.size();
        int col= matrix[0].size();
        vector<vector<int>> lip( row , vector<int> (col, -1)); 
  
         int maxi=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(lip[i][j]==-1)
                {
                    //cout<<"Runs"<<endl;
                    int val=1+dfs(matrix,lip,i,j);
                    maxi=max(maxi,1+dfs(matrix,lip,i,j));
                   // cout<<i<<" "<<j<<" ->"<<lip[i][j]<<" and "<< val<<endl;
                }
            }
        }
        return maxi;
    }
        
       
       
    
};