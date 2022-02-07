class Solution {
public:
    int goldVal(vector<vector<int>>& grid,int x,int y)
    {
        int a=INT_MIN;
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() || grid[x][y]==0)
            return 0;
        else
        {
            int origin=grid[x][y];
            grid[x][y]=0;
            a=max(a,goldVal(grid,x-1,y));
            a=max(a,goldVal(grid,x+1,y));
            a=max(a,goldVal(grid,x,y-1));
            a=max(a,goldVal(grid,x,y+1));
            grid[x][y]=origin;
            return a+origin;
            
        }
    }
  
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int storemax=INT_MIN;
        vector<vector<int>> maxi;
        int store=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    //cout<<" I -"<<i<<" J - "<<j<<endl;
                    store=max(store,goldVal(grid,i,j));
                    //cout<<"Store - "<<store<<endl;
                }
            }
        }
    
        return max(store,0);
    }
};