class Solution {
public:

typedef pair<pair<int,int>, int> pp;
vector<int> dx={-1,0,1,0,-1};
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sx=0,sy=0;
        int tk=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                    sx=i,sy=j;
                if(grid[i][j]>='a' and grid[i][j]<='f')
                   tk++;
            }
        }

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (1<<tk,false)));
        queue<pp> q;
        int c=0;
        q.push({{sx,sy},0});
        vis[sx][sy][0]=true;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first.first,y=it.first.second;
                int cmask=it.second;
                
                if(cmask==((1<<tk)-1))
                    return c;

                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i],ny=y+dx[i+1];
                    int nmask=cmask;
                    if(nx<0 or ny<0 or nx>=n or ny>=m)
                    continue;
                    char ch=grid[nx][ny];
                    if(ch=='#')
                        continue;
                    
                    if(ch>='a' and ch<='f')
                        nmask= (nmask | (1<<(ch-'a')));
                    else if(grid[nx][ny]>='A' and grid[nx][ny]<='F')
                    {
                        char cl=tolower(grid[nx][ny]);
                        int nm= (1<<(cl-'a'));
                        if(!(nm&cmask))
                            continue;
                    }
                    if(vis[nx][ny][nmask])
                                continue;

                    vis[nx][ny][nmask]=1;
                    q.push({{nx,ny},nmask}); 
                    

                }
            }
            c++;
        }
        return -1;
    }
};