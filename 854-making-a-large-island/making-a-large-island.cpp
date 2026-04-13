class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a, int b){
        int pa=find(a);
        int pb=find(b);
 
        if(pa==pb){ 
            return;
        }
        else{
            if(rank[pa]<=rank[pb]){ 
                rank[pb]+=rank[pa];
                parent[pa]=pb;
            }
            else{ 
                rank[pa]+=rank[pb];
                parent[pb]=pa;
            }
        }
    }

    vector<int> dx={-1,0,1,0,-1};

    void pass(int i, int j, int m, int n, vector<vector<int>>& grid, unordered_set<int> &vis)
    { 

        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dx[k+1];

            if(nx>=0 and ny>=0 and nx<m and ny<n and grid[nx][ny]==1 and vis.find(nx*n+ny)==vis.end()){
                 

                vis.insert(nx*n+ny);
                unite(i*n+j,nx*n+ny);
                pass(nx,ny,m,n,grid,vis);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();

        parent.resize(m*n);
        rank.resize(m*n);
 
        for(int i=0;i<m*n;i++){
            rank[i]=0;
            parent[i]=i;
            int r=i/n,c=i%n;
            if(grid[r][c]==1)
                rank[i]=1;
        }

        unordered_set<int> vis;
 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and vis.find(i*n+j)==vis.end()){ 
                    vis.insert(i*n+j);
                    pass(i,j,m,n,grid,vis);
                }
            }
        } 
        int maxi=0;
        bool possible=false; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
 

                    unordered_set<int> pl;

                    for(int k=0;k<4;k++){
                        int nx=i+dx[k],ny=j+dx[k+1];
                        possible=true;
                        if(nx>=0 and ny>=0 and nx<m and ny<n and grid[nx][ny]==1){
                            int p = find(nx*n+ny); 
                            pl.insert(p);
                        }
                    }

                    int curr=0;
 
                    for(auto it:pl)
                        curr+=rank[it];
                    
                    maxi=max(maxi,curr+1);
                }
            }
        }
 

        return possible?maxi:m*n;
    }
};