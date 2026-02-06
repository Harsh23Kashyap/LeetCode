class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;


        int orange=0,rot=0;;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    grid[i][j]=10;
                    q.push({i,j});
                    rot++;
                }
                if(grid[i][j]==1){
                    orange++;
                }
            }
        }
        // cout<<orange<<endl;
        if(orange==0)
        return 0;
        if(rot==0)
        return -1;
        int days=0;
        vector<int> dx={-1,0,1,0,-1};

        while(!q.empty()){
            bool check=false;
            int sz=q.size();
            // cout <<"DAY "<<days<<endl;
            while(sz--){

                auto [x,y]=q.front();
    q.pop();
    // cout<<x<<", "<<y<<endl;
                for(auto l=0;l<4;l++){
                    int nx=dx[l]+x,ny=dx[l+1]+y;
                    if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
                    if(grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=10;
                        orange--;
                        check=true;
                    }
                }
            }
             if(orange==0)
             return days+1;
            days++;

        }
        if(orange!=0)
        return -1;
        return days;


    }
};