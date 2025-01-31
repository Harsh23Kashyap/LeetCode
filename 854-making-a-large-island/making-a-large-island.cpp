class Solution {
public:
    //up down left right
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    //this is the code which calculates the area of different islands currently present in the grid
    int func(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&parent, int currparent){
        queue<pair<int,int>>qu;
        qu.push({i,j});
        grid[i][j] = 0;
        int currsize = 0;
        
        while(qu.empty()==false){
            int i = qu.front().first;
            int j = qu.front().second;
            parent[i][j] = currparent;
            qu.pop();
            currsize++;
            
            for(int d = 0; d<4; d++){
                int currx = i+dx[d];
                int curry = j+dy[d];
                
                if(currx>=0 and curry>=0 and currx<grid.size() and curry<grid[0].size() and grid[currx][curry]==1){
                    grid[currx][curry] = 0;
                    qu.push({currx, curry});
                }
            }
        }
        
        return currsize;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int currparent = 1;
        
        //this map stores the parent of island mapped with its area
        unordered_map<int,int>mp;
        
        //we are using union find in a different way, we are assigning a number to an island using parent matrix
        //different islands have different parents but all the cells of an island have the same parent number
        vector<vector<int>>parent(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    currparent++;
                    int currsize = func(i, j, grid, parent, currparent);
                    mp[currparent] = currsize;
                    ans = max(ans, currsize);
                }
            }
        }

        
        //we are done with the marking of all the islands in the grid, now we will see how much max area we can obtain if we change 0 to 1
        //if the 0 touches the boundary with the cells belonging to different parents then all these islands will accumulate to become a larger island
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(parent[i][j]==0){
                    
                    unordered_set<int>currparents;
                    int currans = 0;
                    
                    for(int d = 0; d<4; d++){
                        int currx = i+dx[d];
                        int curry = j+dy[d];
                        
                        if(currx>=0 and curry>=0 and currx<grid.size() and curry<grid[0].size() and parent[currx][curry]!=0){
                            if(currparents.count(parent[currx][curry])==0){
                                currans+=mp[parent[currx][curry]];
                                currparents.insert(parent[currx][curry]);
                            }
                        }
                    }
                    currans++;
                    ans = max(ans, currans);
                }
            }
        }
        
        return ans;
    }
};