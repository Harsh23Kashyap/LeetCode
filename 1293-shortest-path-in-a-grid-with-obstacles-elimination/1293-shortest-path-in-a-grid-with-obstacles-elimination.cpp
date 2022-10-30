class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        vector<vector<vector<int>>> vis(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -1)));

        int steps=0;
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        queue<vector<int>> q;
        q.push({0,0,k});
        
        while(!q.empty())
        {
           int sz=q.size();
            while(sz--)
            {
                auto curr=q.front();
                q.pop();
                if(curr[0]==grid.size()-1 and curr[1]==grid[0].size()-1)
                    return steps;
                for(auto t:dir)
                {
                    int x=curr[0]+t[0];
                    int y=curr[1]+t[1];
                    if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size())
                    {
                       
                        if(grid[x][y]==0 and vis[x][y][curr[2]]==-1)
                        {
                            q.push({x,y,curr[2]});
                            vis[x][y][curr[2]]=1;
                        }
                        else if(grid[x][y]==1 and curr[2]>0 and vis[x][y][curr[2]-1]==-1)
                        {
                           q.push({x,y,curr[2]-1});
                            vis[x][y][curr[2]-1]=1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};