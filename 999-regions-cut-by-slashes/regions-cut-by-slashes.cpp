class Solution {
public:
    vector<int> dx={-1,0,1,0,-1};
    void exhause(int i, int j,unordered_set<int> &vis,vector<vector<int>>& ng ){
        if(i<0 or j<0 or i>=ng.size() or j>=ng[0].size())
            return;
        
        if(vis.find(i*ng[0].size()+j)!=vis.end())
        return;

        if(ng[i][j]!=0)
            return;
        vis.insert(i*ng[0].size()+j);
        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dx[k+1];
            exhause(nx,ny,vis,ng);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> ng(m*3,vector<int> (n*3,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==' ')
                    continue;
                else if(grid[i][j]=='/')
                {
                        ng[i*3][j*3+2]=1;
                        ng[i*3+1][j*3+1]=1;
                        ng[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                        ng[i*3][j*3]=1;
                        ng[i*3+1][j*3+1]=1;
                        ng[i*3+2][j*3+2]=1;
                    
                }
            }
        }
        // cout<<"Here"<<endl;
        m=ng.size(),n=ng[0].size();
        unordered_set<int> vis;
        int r=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(ng[i][j]==0 and vis.find(i*n+j)==vis.end())
                {
                    r++;
                    exhause(i,j,vis,ng);
                }
            }
        }
        return r;
    }
};